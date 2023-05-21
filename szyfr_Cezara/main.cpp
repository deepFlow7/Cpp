#include <iostream>
#include "wejscie_wyjscie.hpp"

using namespace std;

bool duza_litera(char x)
{
    return (x >= 'A' && x <= 'Z');
}

bool mala_litera(char x)
{
    return (x >= 'a' && x <= 'z');
}

std::string szyfruj(int n,std::string wyraz)
{
    std::string z = "";
    for(unsigned int i=0; i<wyraz.size(); i++)
        if(mala_litera(wyraz[i]))
            z += 'a' + (wyraz[i] - 'a' + n)%26;
        else
            if(duza_litera(wyraz[i]))
                z += 'A' + (wyraz[i] - 'A' + n)%26;
    return z;
}

void pisz(wejscie *we, wyjscie *wy, int n)
{
    while(!we->koniec_pliku())
        wy->pisz_linie(szyfruj(n, we->nast_linia()));
}

int main(int argc, char * argv[])
{
    if(argc != 4)
    {
        cout << "Niepoprawna liczba argumentów."<< endl;
        return 0;
    }

    wejscie *we = new wejscie(argv[1]);
    wyjscie *wy = new wyjscie(argv[2]);
    int n = stoi(argv[3]);

    pisz(we, wy, n);

    we->~wejscie();
    wy->~wyjscie();
}
