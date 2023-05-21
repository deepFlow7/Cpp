#include "wymierna.hpp"
#include "errors.hpp"
#include <string>
#include <iostream>
#include <climits>

using namespace obliczenia;

int nwd(int l,int m) noexcept
{
    if(l<m)
    {
        int p=l;
        l=m;
        m=p;
    }
    if(m==0)
        return l;
    return nwd(l%m,m);
}

wymierna::wymierna(int l,int m) noexcept(false)
{
    if (m==0)
        throw zerowy_mainownik();
    if (m<0)
    {
        m=-m;
        l=-l;
    }
    int n = nwd(abs(l),abs(m));
    licz = l/n;
    mian = m/n;
}

wymierna::wymierna(double x) noexcept(false)
{
    int m = 1;
    while (x - (int)x != 0)
    {
        m *= 10;
        x *= 10;
    }

    if(x < INT_MIN || x > INT_MAX)
        throw nieudana_konwersja();

    wymierna w((int)x,m);
    licz = w.licznik();
    mian = w.mianownik();
}

wymierna::~wymierna() noexcept
{
    licz = mian = 0;
}

int wymierna::licznik() noexcept
{
    return licz;
}

int wymierna::mianownik() noexcept
{
    return mian;
}

void zakres_dodawanie(int a, int b) noexcept(false)
{
    if ((a<0 && b<0 && a+b>0) || (a>0 && b>0 && a+b<0))
        throw przekroczenie_zakresu();
}

void zakres_mnozenie(int a, int b) noexcept(false)
{
    if (abs(a) > INT_MAX / abs(b))
        throw przekroczenie_zakresu();
}

wymierna wymierna::operator+(wymierna w) noexcept(false)
{
    int l1, l2, m1, m2, l, m, n;

    l1 = this->licznik(), l2 = w.licznik();
    m1 = this->mianownik(), m2 = w.mianownik();

    n = nwd(abs(m1), abs(m2));
    zakres_dodawanie(l1 * m2/n, l2 * m1/n);
    l = l1 * m2/n + l2 * m1/n;
    m = m1/n * m2;
    return wymierna(l,m);
}

wymierna wymierna::operator-(wymierna w) noexcept(false)
{
    return *this + -w;
}

wymierna wymierna::operator * (wymierna w) noexcept(false)
{
    int l1, l2, m1, m2, l, m, n1, n2;

    l1 = this->licznik(), l2 = w.licznik();
    m1 = this->mianownik(), m2 = w.mianownik();

    n1 = nwd(abs(l1),abs(m2));
    n2 = nwd(abs(l2),abs(m1));

    l = l1/n1 * (l2/n2);
    m = m1/n2 * (m2/n1);

    return wymierna(l,m);
}

wymierna wymierna::operator / (wymierna w) noexcept(false)
{
    return *this * !w;
}

wymierna wymierna::operator - () noexcept(false)
{
    if (this->licznik() == INT_MIN)
        throw przekroczenie_zakresu();
    return wymierna(-this->licznik(),this->mianownik());
}

wymierna wymierna::operator ! () noexcept(false)
{
    if (this->licznik() == 0)
        throw zerowy_mainownik();
    return wymierna(this->mianownik(), this->licznik());
}

wymierna::operator double() noexcept
{
    return (double)this->licznik() / this->mianownik();
}

wymierna::operator int() noexcept
{
    int calkowita = this->licznik() / this->mianownik();
    if (2 * abs(this->licznik()) == this->mianownik())
        calkowita++;
    else if (2 * abs(this->licznik()) > this->mianownik())
    {
        if (calkowita >= 0)
            calkowita++;
        else
            calkowita--;
    }
    return calkowita;
}

namespace obliczenia
{
    std::ostream& operator<< (std::ostream &wyj, const wymierna &w) noexcept
    {
        if (w.licz<0)
            wyj<<'-';
        int l = abs(w.licz), m = w.mian;
        wyj<< l / m;
        l = l % m;
        if (l != 0)
        {
            wyj<<',';
            int *reszty = new int[m];
            for(int i=0;i<m;i++)
                reszty[i] = -1;
            std::string s = "";
            int okresowe = -1;
            int i = 0;
            while (l != 0 && okresowe == -1)
            {
                l *= 10;
                if (reszty[l%m] != -1)
                    okresowe = reszty[l%m];
                else
                {
                    reszty[l%m] = i;
                    s = s + std::to_string(l/m);
                }
                l = l % m;
                i++;
            }
            if (okresowe != -1)
            {
                s = s + ")";
                s.insert(okresowe,"(");
            }
            wyj<<s;
        }
        return wyj;
    }
}
