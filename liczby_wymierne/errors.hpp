#include <stdexcept>

class wyjatek_wymierny : public std::logic_error
{
public :
    wyjatek_wymierny(const char *info) : logic_error(info){}
};

class zerowy_mainownik : public wyjatek_wymierny
{
public :
    zerowy_mainownik() : wyjatek_wymierny("Mianownik nie może być zerem") {};
};

class dzielenie_przez_zero : public wyjatek_wymierny
{
public :
    dzielenie_przez_zero() : wyjatek_wymierny("Dzielenie przez 0") {};
};

class przekroczenie_zakresu : public wyjatek_wymierny
{
public :
    przekroczenie_zakresu() : wyjatek_wymierny("Nie można zaraprezentować liczby jako obiekt klasy 'wymierna'") {};
    przekroczenie_zakresu(const char *info) : wyjatek_wymierny(info) {};
};

class nieudana_konwersja : public przekroczenie_zakresu
{
public :
    nieudana_konwersja() : przekroczenie_zakresu("Konwersja liczby double na liczbę wymierną nie powiodła się") {};
};
