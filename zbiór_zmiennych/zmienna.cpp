#include <iostream>
#include <string>
#include "zmienna.hpp"

static bool czy_cyfra(char x)
{
    if(x>='0' && x<='9')
        return true;
    return false;
}
static bool czy_litera(char x)
{
    if((x>='a' && x<='z') || (x>='A' && x<='Z'))
        return true;
    return false;
}
static bool dozwolony_znak(char x)
{
    if(czy_cyfra(x) || x=='_' || czy_litera(x))
        return true;
    return false;
}
static bool czy_poprawna_nazwa(std::string nazwa)
{
    if(nazwa=="" || czy_cyfra(nazwa[0]))
        return false;
    int dlugosc_nazwy=nazwa.size();
    for(int i=2; i<dlugosc_nazwy; i++)
        if(!dozwolony_znak(nazwa[i]))
            return false;
    return true;
}
zmienna::zmienna(std::string nazwa)
{
    if(czy_poprawna_nazwa(nazwa))
    {
        this->nazwa=nazwa;
        this->wartosc=0;
    }
    else
        throw std::invalid_argument("Niedozwolona nazwa zmiennej");

}
zmienna::zmienna(std::string nazwa, double wartosc):wartosc(wartosc)
{
    if(czy_poprawna_nazwa(nazwa))
    {
        this->nazwa=nazwa;
    }
    else
        throw std::invalid_argument("Niedozwolona nazwa zmiennej");
}
std::string zmienna::nazwa_zmiennej()
{
    return nazwa;
}
double zmienna::wartosc_zmiennej()
{
    return wartosc;
}
void zmienna::ustaw_wartosc_zmiennej(double wartosc)
{
    this->wartosc=wartosc;
}
