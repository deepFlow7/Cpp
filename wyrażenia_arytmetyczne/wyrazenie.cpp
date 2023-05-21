#include <iostream>
#include "wyrazenie.hpp"

std::vector<std::pair<std::string, double>> zmienna::zbior_zmiennych;

liczba::liczba(double x)
{
    this->x=x;
}

double liczba::oblicz()
{
    return x;
}

std::string liczba::zapis()
{
    return std::to_string(x);
}

zmienna::zmienna(std::string nazwa)
{
    this->nazwa=nazwa;
}

void zmienna::dodaj_do_zbioru(std::pair<std::string, double> p)
{
    zbior_zmiennych.push_back(p);
}

int pozycja(std::vector<std::pair<std::string, double>> v,std::string nazwa)
{
    uint32_t i=0;
    while (i<v.size() && v[i].first!=nazwa)
        i++;
    if(i<v.size())
        return i;
    throw "Zmienna o tej nazwie nie wystepuje w zbiorze";
}

void zmienna::usun_ze_zbioru(std::string nazwa_zmiennej)
{
    zbior_zmiennych.erase(zbior_zmiennych.begin()+pozycja(zbior_zmiennych,nazwa_zmiennej));
}

void zmienna::modyfikuj_zmienna_w_zbiorze(std::string nazwa_zmiennej, double nowa_wartosc)
{
    usun_ze_zbioru(nazwa_zmiennej);
    dodaj_do_zbioru(std::make_pair(std::string(nazwa_zmiennej),nowa_wartosc));
}

double zmienna::oblicz()
{
    return zbior_zmiennych[pozycja(zbior_zmiennych,nazwa)].second;
}

std::string zmienna::zapis()
{
    return nazwa;
}

stala::stala(std::string nazwa, double wartosc)
{
    this->nazwa=nazwa;
    this->wartosc=wartosc;
}

double stala::oblicz()
{
    return wartosc;
}

std::string stala::zapis()
{
    return nazwa;
}
