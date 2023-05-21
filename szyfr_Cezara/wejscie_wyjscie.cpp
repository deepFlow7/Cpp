#include "wejscie_wyjscie.hpp"

wejscie::wejscie(std::string nazwa)
{
    we.open(nazwa);
    if (we.fail())
        throw "Nie można otworzyć pliku.";
    we.exceptions(std::ios::failbit | std::ios::badbit);
}

wejscie::~wejscie()
{
    we.close();
}

std::string wejscie::nast_linia()
{
    std::string wynik = "";
    try
    {
        getline(we,wynik);
    }
    catch(std::ios_base::failure e)
    {
        return "";
    }
    return wynik;
}

bool wejscie::koniec_pliku()
{
    return we.eof();
}

wyjscie::wyjscie(std::string nazwa)
{
    wy.open(nazwa);
    if (wy.fail())
        throw "Nie można otworzyć pliku.";
    wy.exceptions(std::ios::failbit | std::ios::badbit);
}

wyjscie::~wyjscie()
{
    wy.close();
}

void wyjscie::pisz_linie(std::string linia)
{
    wy<<linia<<"\n";
}
