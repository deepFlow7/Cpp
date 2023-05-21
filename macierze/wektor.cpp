#include "wektor.hpp"
#include <iostream>

using namespace obliczenia;

wektor::wektor(int k) : k(k)
{
    if(k<0)
        throw new ujemny_rozmiar_wektora();
    tab=new double[k];
    for(int i=0;i<k;i++)
        tab[i] = 0;
}

wektor::wektor(wektor &w) : k(w.k)
{
    tab=new double[k];
    for(int i=0;i<k;i++)
        tab[i] = w.tab[i];
}

wektor::wektor(std::initializer_list<double> l) : k(l.size())
{
    tab=new double[k];
    std::copy(l.begin(), l.end(), tab);
}

wektor::~wektor()
{
    delete[] tab;
}

namespace obliczenia
{
    int rozmiar(const wektor *w)
    {
        return (int)w->k;
    }
}

wektor& wektor::operator = (const wektor &w)
{
    if (k != w.k)
        throw new zmiana_rozmiaru_wektora();
    if (this != &w)
    {
        delete[] tab;
        tab=new double[k];
        std::copy(w.tab,w.tab+k,tab);
    }
    return *this;
}

wektor& wektor::operator = (wektor &&w)
{
    if (k != w.k)
        throw new zmiana_rozmiaru_wektora();
    if (this != &w)
    {
        delete[] tab;
        tab=w.tab;
        w.tab=nullptr;
    }
    return *this;
}

namespace obliczenia
{
    wektor operator-(const wektor &v)
    {
        wektor w(v.k);
        for(int i=0;i<w.k;i++)
            w.tab[i] = -v.tab[i];
        return w;
    }

    wektor operator+(const wektor &x, const wektor &y)
    {
        if (x.k != y.k)
            throw new rozne_rozmiary_wektorow(" przy dodawaniu");
        wektor w(x.k);
        for(int i=0;i<w.k;i++)
            w.tab[i] = x.tab[i] + y.tab[i];
        return w;
    }

    wektor operator-(const wektor &x, const wektor &y)
    {
        if (x.k != y.k)
            throw new rozne_rozmiary_wektorow(" przy odejmowawaniu");
        wektor w(x.k);
        for(int i=0;i<w.k;i++)
            w.tab[i] = x.tab[i] - y.tab[i];
        return w;
    }

    wektor operator*(const wektor &v, double d)
    {
        wektor w(v.k);
        for(int i=0;i<w.k;i++)
            w.tab[i] = v.tab[i] * d;
        return w;
    }

    wektor operator*(double d, const wektor &v)
    {

        return v*d;

    }

    double operator*(const wektor &x, const wektor &y)
    {
        if (x.k != y.k)
            throw new rozne_rozmiary_wektorow(" w iloczynie skalarnym");
        double s=0;
        for(int i=0;i<x.k;i++)
            s += x.tab[i] * y.tab[i];
        return s;
    }
}

wektor& wektor::operator+=(const wektor &v)
{
    if (k != v.k)
        throw new rozne_rozmiary_wektorow(" przy dodawaniu");
    for(int i=0;i<k;i++)
        tab[i] += v.tab[i];
    return *this;
}

wektor& wektor::operator-=(const wektor &v)
{
    if (k != v.k)
        throw new rozne_rozmiary_wektorow(" przy odejmowaniu");
    for(int i=0;i<k;i++)
        tab[i] -= v.tab[i];
    return *this;
}

wektor& wektor::operator*=(double d)
{
    for(int i=0;i<k;i++)
        tab[i] *= d;
    return *this;
}

double  wektor::operator[](int i) const
{
    if(i<0 || i>= k)
        throw new niepoprawny_index();
    return tab[i];
}

double& wektor::operator[](int i)
{
    if(i<0 || i>= k)
        throw new niepoprawny_index();
    return tab[i];
}

namespace obliczenia
{
    std::istream & operator >> (std::istream &we, wektor &v)
    {
        for(int i=0;i<v.k;i++)
            we>>v[i];
        return we;
    }

    std::ostream & operator << (std::ostream &wy, const wektor &v)
    {
         wy<<'(';
         for(int i=0;i<v.k;i++)
         {
            wy<<v[i];
            if(i != v.k-1)
                wy<<','<<' ';
         }
         wy<<')';
         return wy;
    }
}
