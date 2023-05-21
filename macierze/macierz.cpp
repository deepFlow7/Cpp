#include "macierz.hpp"
#include <iostream>

using namespace obliczenia;

macierz::macierz(int w, int k) : w(w), k(k)
{
    tab=new wektor*[w];
    for(int i=0;i<w;i++)
        tab[i] = new wektor(k);
}

macierz::macierz(macierz &m) : w(m.w), k(m.k)
{
    tab=new wektor*[w];
    for(int i=0;i<w;i++)
        tab[i] = new wektor(*(m.tab[i]));
}

macierz::macierz(std::initializer_list<wektor> l) : w(l.size()), k(rozmiar(l.begin()))
{
    tab=new wektor*[w];
    for(int i=0;i<w;i++)
        if(rozmiar(l.begin()+i) != k)
            throw new rozne_rozmiary_wektorow(" macierzy");
        else
            tab[i]= new wektor((wektor&)*(l.begin()+i));
}

macierz::~macierz()
{
    for(int i=0;i<w;i++)
        delete[] tab[i];
    delete[] tab;
}

macierz& macierz::operator = (const macierz &m)
{
    if (k != m.k || w != m.w)
        throw new zmiana_rozmiaru_macierzy();
    if (this != &m)
    {
        for(int i=0;i<w;i++)
        {
           (*tab[i]).~wektor();
           for(int i=0;i<w;i++)
             tab[i] = new wektor(*(m.tab[i]));
         }
    }
    return *this;
}

macierz& macierz::operator = (macierz &&m)
{
    if (k != m.k || w != m.w)
        throw new zmiana_rozmiaru_macierzy();
    if (this != &m)
    {
        for(int i=0;i<w;i++)
            delete[] tab[i];
        delete[] tab;
        tab=m.tab;
        m.tab=nullptr;
    }
    return *this;
}

namespace obliczenia
{
    macierz& operator-(const macierz &m)
    {
        macierz *n = new macierz((macierz&)m);
        for(int i=0;i<n->w;i++)
            *(n->tab[i]) *= -1;
        return *n;
    }

    macierz& operator+(const macierz &p, const macierz &q)
    {
        if (p.k != q.k || p.w != q.w)
            throw new rozne_rozmiary_macierzy(" przy dodawaniu");
        macierz *n = new macierz((macierz&)p);
        for(int i=0;i<n->w;i++)
            *(n->tab[i]) += *(q.tab[i]);
        return *n;
    }

    macierz& operator-(const macierz &p, const macierz &q)
    {
        if (p.k != q.k || p.w != q.w)
            throw new rozne_rozmiary_macierzy(" przy odejmowaniu");
        macierz *n = new macierz((macierz&)p);
        for(int i=0;i<n->w;i++)
            *(n->tab[i]) -= *(q.tab[i]);
        return *n;
    }

    macierz& operator*(const macierz &m, double d)
    {
        macierz *n = new macierz((macierz&)m);
        for(int i=0;i<n->w;i++)
            *(n->tab[i]) *= d;
        return *n;
    }

    macierz& operator*(double d, const macierz &m)
    {
        return m*d;
    }

    macierz& operator*(const macierz &p, const macierz &q)
    {
        if (p.k != q.w)
            throw new rozne_rozmiary_macierzy(" przy mnożeniu");
        macierz *n = new macierz(p.w,q.k);
        for(int i=0;i<n->w;i++)
            for(int j=0;j<n->k;j++)
                for(int t=0;t<p.k;t++)
                    (*n)[i][j] += p[i][t] * q[t][j];
        return *n;
    }

    macierz& operator~(const macierz &m)
    {
        macierz *n = new macierz(m.k,m.w);
        for(int i=0;i<n->w;i++)
            for(int j=0;j<n->k;j++)
                (*n)[i][j] = m[j][i];
        return *n;
    }
}

macierz& macierz::operator+=(const macierz &m)
{
    if (k != m.k || w != m.w)
        throw new rozne_rozmiary_macierzy(" przy dodawaniu");
    for(int i=0;i<w;i++)
        *tab[i] += *m.tab[i];
    return *this;
}

macierz& macierz::operator-=(const macierz &m)
{
    if (k != m.k || w != m.w)
        throw new rozne_rozmiary_macierzy(" przy odejmowaniu");
    for(int i=0;i<k;i++)
        *tab[i] -= *m.tab[i];
    return *this;
}

macierz& macierz::operator*=(double d)
{
    for(int i=0;i<k;i++)
        *tab[i] *= d;
    return *this;
}

wektor macierz::operator[](int i) const
{
    if(i<0 || i>= w)
        throw new niepoprawny_index();
    return *tab[i];
}

wektor& macierz::operator[](int i)
{
    if(i<0 || i>= w)
        throw new niepoprawny_index();
    return *(tab[i]);
}

namespace obliczenia
{
    std::istream & operator >> (std::istream &we, macierz &m)
    {
        for(int i=0;i<m.w;i++)
            we>>m[i];
        return we;
    }

    std::ostream & operator << (std::ostream &wy, const macierz &m)
    {
        for(int i=0;i<m.w;i++)
        {
            if(i==0)
                wy<<'[';
            else
                wy<<' ';
            wy<<m[i];
            if(i==m.w-1)
                wy<<']';
            wy<<'\n';
        }
         return wy;
    }
}

