#include "kolor.hpp"

void poprawnosc(int n)
{
    if(n<0 || n>255)
        throw "Nieprawidlowe nasycenie";
}

kolor::kolor():r(0), g(0), b(0)
{
}

kolor::kolor(int r, int g, int b)
{
    poprawnosc(r);
    poprawnosc(g);
    poprawnosc(b);
    this->r=r;
    this->g=g;
    this->b=b;
}

int kolor::get_r()
{
    return r;
}

int kolor::get_g()
{
    return g;
}

int kolor::get_b()
{
    return b;
}

void kolor::set_r(int n)
{
    poprawnosc(n);
    r=n;
}

void kolor::set_g(int n)
{
    poprawnosc(n);
    g=n;
}

void kolor::set_b(int n)
{
    poprawnosc(n);
    b=n;
}

void kolor::rozjasnij_r(int i)
{
    poprawnosc(r-i);
    r-=i;
}

void kolor::przyciemnij_r(int i)
{
    rozjasnij_r(-i);
}

void kolor::rozjasnij_g(int i)
{
    poprawnosc(g-i);
    g-=i;
}

void kolor::przyciemnij_g(int i)
{
    rozjasnij_g(-i);
}

void kolor::rozjasnij_b(int i)
{
    poprawnosc(b-i);
    b-=i;
}

void kolor::przyciemnij_b(int i)
{
    rozjasnij_b(-i);
}

int kolor::suma()
{
    return (r+b+g)/3;
}

kolortransparentny::kolortransparentny(int r,int g,int b,int alfa):kolor(r,g,b)
{
    this->alfa=alfa;
}

void kolortransparentny::ustaw_alfe(int a)
{
    poprawnosc(a);
    alfa=a;
}

int kolortransparentny::get_alfa()
{
    return alfa;
}

void kolornazwany::nazwij(std::string nazwa)
{
    for(uint32_t i=0;i<nazwa.size();i++)
        if((nazwa[i]>'z' || nazwa[i]<'a') && (nazwa[i]>'Z' || nazwa[i]<'A'))
            throw "Nieprawidlowa nazwa koloru";
    this->nazwa=nazwa;
}

std::string kolornazwany::nazwa_koloru()
{
    return nazwa;
}
