#include <iostream>
#include <string>
#include <list>
#include "kolejka.hpp"

kolejka::kolejka():kolejka(1)
{
}

kolejka::kolejka(int pojemnosc)
{
    if(pojemnosc<=0)
        throw "Nie mozna utworzyc kolejki o niedodatniej pojemnosci";
    this->pojemnosc=pojemnosc;
    tab=new std::string[pojemnosc];
}

kolejka::kolejka(std::initializer_list<std::string> l):kolejka(l.size())
{
    std::copy(l.begin(), l.end(), tab);
    ile=l.size();
}

kolejka::kolejka(kolejka &k):kolejka(k.pojemnosc)
{
    poczatek=k.poczatek;
    ile=k.ile;
    std::copy(k.tab,k.tab+k.pojemnosc,tab);
}

kolejka& kolejka::operator= (kolejka &k)
{
    if (this != &k)
    {
        delete[] tab;
        tab=new std::string[k.dlugosc()];
        std::copy(k.tab, k.tab+k.pojemnosc,tab);
        pojemnosc=k.pojemnosc;
        poczatek=k.poczatek;
        ile=k.ile;
    }
    return *this;
}

kolejka::kolejka(kolejka &&k):kolejka(k.pojemnosc)
{
    poczatek=k.poczatek;
    ile=k.ile;
    tab=k.tab;
    delete[] k.tab;
    k.tab=nullptr;
}

kolejka& kolejka::operator= (kolejka &&k)
{
    if (this != &k)
    {
        pojemnosc=k.pojemnosc;
        poczatek=k.poczatek;
        ile=k.ile;
        delete[] tab;
        tab=k.tab;
        k.tab=nullptr;
    }
    return *this;
}

kolejka::~kolejka()
{
    delete[] tab;
}

void kolejka::wstaw(std::string s)
{
    if(ile<pojemnosc)
    {
        int poz=(poczatek+ile)%pojemnosc;
        tab[poz]=s;
        ile++;
    }
    else
        throw "Nie udalo sie wstawic elementu do kolejki";
}

std::string kolejka::usun()
{
    if(ile>0)
    {
        std::string pom=tab[poczatek];
        poczatek=(poczatek+1)%pojemnosc;
        ile--;
        return pom;
    }
    else
        throw "Brak elementow w kolejce";
}

std::string kolejka::z_przodu()
{
    if(ile>0)
        return tab[poczatek];
    else
        throw "Brak elementow w kolejce";
}

int kolejka::dlugosc()
{
    return ile;
}

