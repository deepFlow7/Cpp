#include <cmath>
#include "tabbit.hpp"

using namespace obliczenia;

const int tabbit::rozmiarSlowa=64;

bool tabbit::ref::czytaj_bit(int i,uint64_t *tab)
{
    int rozm=tabbit::rozmiarSlowa;
    return tab[i/rozm]>>(rozm-i%rozm-1)&1;
}

void tabbit::ref::ustaw_bit(int i,uint64_t *tab,bool wartosc)
{
    int rozm=tabbit::rozmiarSlowa;
    if(wartosc)
        tab[i/rozm]|=1ull<<(rozm-i%rozm-1);
    else
        tab[i/rozm]&=~(1ull<<(rozm-i%rozm-1));
}

bool tabbit::ref::czytaj()
{
    return this->czytaj_bit(i,tab);
}

bool tabbit::czytaj(int i) const
{
    if(i<0 || i>=this->dl)
        throw "Błąd zakresu";
    ref r;
    return r.czytaj_bit(i,tab);
}

void tabbit::pisz(int i, bool b)
{
    if(i<0 || i>=this->dl)
        throw "Błąd zakresu";
    ref r;
    r.ustaw_bit(i,tab,b);
}

namespace obliczenia
{
    std::istream & operator >> (std::istream &we, tabbit &tb)
    {
        std::cout<<"Podaj liczbe bitow : ";
        we>>tb.dl;
        if(tb.dl<=0)
            throw "Liczba bitów musi być dodatnia";
        std::cout<<"Podaj bity : ";

        int roz=ceil((tb.dl+1)/tabbit::rozmiarSlowa);
        delete[] tb.tab;
        tb.tab=new tabbit::slowo[roz];
        bool b;

        for(int i=0;i<tb.dl;i++)
        {
            we>>b;
            tb.pisz(i,b);
        }
        return we;
    }
}

namespace obliczenia
{
    std::ostream & operator << (std::ostream &wy, const tabbit &tb)
    {
        for(int i=0;i<tb.rozmiar();i++)
            wy<<tb.czytaj(i);
        return wy;
    }
}

tabbit::tabbit(int rozm)
{
    if(rozm<0)
       throw "Liczba bitów nie może być ujemna";
    int rozmiar_tab=ceil((rozm+1)/tabbit::rozmiarSlowa);
    dl=rozm;
    tab=new slowo[rozmiar_tab];
    for(int i=0;i<rozmiar_tab;i++)
        tab[i]=0;
}

tabbit::tabbit(slowo tb)
{
    dl=tabbit::rozmiarSlowa;
    tab=new slowo[1];
    tab[0]=tb;
}

tabbit::~tabbit()
{
    delete[] tab;
}

tabbit::tabbit(const tabbit &tb)
{
    dl=tb.dl;
    int rozmiar_tab=ceil((tb.dl+1)/tabbit::rozmiarSlowa);
    tab=new slowo[rozmiar_tab];
    for(int i=0;i<rozmiar_tab;i++)
        tab[i]=tb.tab[i];
}

tabbit::tabbit(tabbit &&tb)
{
    dl=tb.dl;
    tab=tb.tab;
    tb.tab=nullptr;
}

int tabbit::rozmiar() const
{
    const int i=dl;
    return i;
}

tabbit& tabbit::operator = (const tabbit &tb)
{
    if (this != &tb)
    {
        delete[] tab;
        this->dl=tb.dl;
        int rozmiar_tab=ceil((tb.dl+1)/tabbit::rozmiarSlowa);
        tab=new slowo[rozmiar_tab];
        for(int i=0;i<rozmiar_tab;i++)
            tab[i]=tb.tab[i];
    }
    return *this;
}

tabbit& tabbit::operator = (tabbit &&tb)
{
    if (this != &tb)
    {
        delete[] tab;
        tab=tb.tab;
        dl=tb.dl;
        tb.tab=nullptr;
    }
    return *this;
}

bool tabbit::operator [] (int i) const
{
    if(i<0 || i>=this->dl)
        throw "Błąd zakresu";
    return czytaj(i);
}

tabbit::ref tabbit::operator [] (int i)
{
    if(i<0 || i>=this->dl)
        throw "Błąd zakresu";
    ref *r=new ref(i,(uint64_t*)this->tab);
    return *r;
}

tabbit tabbit::operator | (tabbit &tb)
{
    int roz_max=this->dl;
    int roz_min=tb.dl;
    if(roz_max<tb.dl)
    {
        roz_max=tb.dl;
        roz_min=this->dl;
    }
    tabbit wyn(roz_max);
    for(int i=0;i<roz_min;i++)
        wyn.pisz(i,this->czytaj(i)|tb.czytaj(i));
    if(this->dl>tb.dl)
        for(int i=roz_min;i<this->dl;i++)
            wyn.pisz(i,this->czytaj(i));
    else
        for(int i=roz_min;i<tb.dl;i++)
            wyn.pisz(i,tb.czytaj(i));
    return wyn;
}

void tabbit::operator |= (tabbit &tb)
{
    *this = *this | tb;
}

tabbit tabbit::operator & (tabbit &tb)
{
    int roz_max=this->dl;
    int roz_min=tb.dl;
    if(roz_max<tb.dl)
    {
        roz_max=tb.dl;
        roz_min=this->dl;
    }
    tabbit wyn(roz_max);
    for(int i=0;i<roz_min;i++)
        wyn.pisz(i,this->czytaj(i)&tb.czytaj(i));
    if(this->dl>tb.dl)
        for(int i=roz_min;i<this->dl;i++)
            wyn.pisz(i,this->czytaj(i));
    else
        for(int i=roz_min;i<tb.dl;i++)
            wyn.pisz(i,tb.czytaj(i));
    return wyn;
}

void tabbit::operator &= (tabbit &tb)
{
    *this = *this & tb;
}

tabbit tabbit::operator ^ (tabbit &tb)
{
    int roz_max=this->dl;
    int roz_min=tb.dl;
    if(roz_max<tb.dl)
    {
        roz_max=tb.dl;
        roz_min=this->dl;
    }
    tabbit wyn(roz_max);
    for(int i=0;i<roz_min;i++)
        wyn.pisz(i,this->czytaj(i)^tb.czytaj(i));
    if(this->dl>tb.dl)
        for(int i=roz_min;i<this->dl;i++)
            wyn.pisz(i,this->czytaj(i));
    else
        for(int i=roz_min;i<tb.dl;i++)
            wyn.pisz(i,tb.czytaj(i));
    return wyn;
}

void tabbit::operator ^= (tabbit &tb)
{
    *this = *this ^ tb;
}

tabbit tabbit::operator ! ()
{
    tabbit wyn(this->dl);
    for(int i=0;i<this->dl;i++)
        wyn.pisz(i,!(this->czytaj(i)));
    return wyn;
}

