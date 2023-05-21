#include <iostream>
#include "operator2arg.hpp"

void test(wyrazenie *w)
{
    std::cout<<w->zapis();
    std::cout<<", wartosc : "<<w->oblicz()<<"\n\n";
}

void test_ze_zmienna_wartoscia(std::string nazwa, double wartosc_poczatkowa, double skok, uint32_t ile_zmian, wyrazenie *w)
{
    zmienna::modyfikuj_zmienna_w_zbiorze(nazwa,wartosc_poczatkowa);
    std::cout<<"    Wartosc x : "<<wartosc_poczatkowa<<", wartosc wyrazenia : "<<w->oblicz()<<"\n";
    for(uint32_t i=1;i<=ile_zmian;i++)
    {
        zmienna::modyfikuj_zmienna_w_zbiorze(nazwa,wartosc_poczatkowa+i*skok);
        std::cout<<"    Wartosc x : "<<wartosc_poczatkowa+i*skok<<", wartosc wyrazenia : "<<w->oblicz()<<"\n";
    }
    std::cout<<"\n";
}

int main()
{
    zmienna::dodaj_do_zbioru(std::make_pair(std::string("x"),1));

    wyrazenie *w1 = new odejmij(new pi(), new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7))));
    test(w1);

    wyrazenie *w2 = new dziel(new mnoz(new odejmij(new zmienna("x"), new liczba(1)), new zmienna("x")), new liczba(2));
    test(w2);

    wyrazenie *w3 = new dziel(new cosinus(new mnoz(new dodaj(new zmienna("x"), new liczba(1)), new pi())),
                              (new potega(new e(), new potega(new zmienna("x"), new liczba(2)))));
    test(w3);
    test_ze_zmienna_wartoscia("x",0,0.1,10,w3);

    return 0;
}
