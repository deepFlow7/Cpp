#include <iostream>
#include <string>
#include "zmienna.hpp"
#include "zbior_zmiennych.hpp"

zbior_zmiennych::zbior_zmiennych(int rozmiar):n(rozmiar)
{
    if(rozmiar<0)
        throw std::invalid_argument("Rozmiar zbioru nie moze byc ujemny");
    tab=new zmienna[rozmiar];
}
zbior_zmiennych::~zbior_zmiennych()
{
    delete[] tab;
}
void zbior_zmiennych::wstaw_do_zbioru(zmienna z)
{
    int i=0;
    while(i<n && tab[i].nazwa_zmiennej()!="_" && tab[i].nazwa_zmiennej()!=z.nazwa_zmiennej())
        i++;
    if(i<n)
    {
        if(tab[i].nazwa_zmiennej()!=z.nazwa_zmiennej())
            tab[i]=z;
        else
            throw std::invalid_argument("Zmienna o tej nazwie juz znajduje sie w zbiorze");
    }
}
bool zbior_zmiennych::czy_w_zbiorze(std::string nazwa_zmiennej)
{
    int i=0;
    while(i<n && tab[i].nazwa_zmiennej()!=nazwa_zmiennej)
        i++;
    if(i<n)
        return 1;
    return 0;
}
void zbior_zmiennych::usun_ze_zbioru(std::string nazwa_zmiennej)
{
    int i=0;
    while(i<n && tab[i].nazwa_zmiennej()!=nazwa_zmiennej)
        i++;
    if(i<n)
    {
        for(int j=i; j<n-1; j++)
            tab[j]=tab[j+1];
        tab[n-1]=zmienna();
    }
    else
        std::cerr<<"Zmienna nie zostala usunieta (w zbiorze nie ma zmiennej o takiej nazwie)"<<std::endl;

}
double zbior_zmiennych::wartosc_zmiennej(std::string nazwa_zmiennej)
{
    int i=0;
    while(i<n && tab[i].nazwa_zmiennej()!=nazwa_zmiennej)
        i++;
    if(i<n)
        return tab[i].wartosc_zmiennej();
    throw std::invalid_argument("Zmienna nie wystepuje w zbiorze");
}
void zbior_zmiennych::zmien_wartosc_zmiennej(std::string nazwa_zmiennej, double nowa_wartosc)
{
    int i=0;
    while(i<n && tab[i].nazwa_zmiennej()!=nazwa_zmiennej)
        i++;
    if(i<n)
        tab[i].ustaw_wartosc_zmiennej(nowa_wartosc);
}
