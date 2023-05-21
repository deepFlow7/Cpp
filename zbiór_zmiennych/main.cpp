#include <iostream>
#include "zmienna.hpp"
#include "zbior_zmiennych.hpp"

int main()
{
    zmienna z_1;
    zmienna z_2=zmienna("druga");
    zmienna z_3=zmienna("trzecia",5);

    std::cout<<"Nazwa zmiennej z_2: "<<z_2.nazwa_zmiennej()<<std::endl;
    std::cout<<"Wartosc zmiennej z_3: "<<z_3.wartosc_zmiennej()<<std::endl;
    z_3.ustaw_wartosc_zmiennej(18);
    std::cout<<"Nowa wartosc zmiennej z_3: "<<z_3.wartosc_zmiennej()<<std::endl<<std::endl;


    zbior_zmiennych zbior=zbior_zmiennych(10);
    zbior.wstaw_do_zbioru(z_2);
    zbior.wstaw_do_zbioru(z_3);

    std::cout<<"Wartosc zmiennej o nazwie z_2: "<<zbior.wartosc_zmiennej(z_2.nazwa_zmiennej())<<std::endl;
    zbior.zmien_wartosc_zmiennej(z_2.nazwa_zmiennej(),1.5);
    std::cout<<"Nowa wartosc zmiennej o nazwie z_2: "<<zbior.wartosc_zmiennej(z_2.nazwa_zmiennej())<<std::endl<<std::endl;

    std::cout<<"Czy zmienna o nazwie z_2 jest w zbiorze? "<<zbior.czy_w_zbiorze(z_2.nazwa_zmiennej())<<std::endl;
    zbior.usun_ze_zbioru(z_2.nazwa_zmiennej());
    std::cout<<"Usunieto zmienna o nazwie z_2 ze zbioru"<<std::endl;
    std::cout<<"Czy teraz zmienna o nazwie z_2 jest w zbiorze? "<<zbior.czy_w_zbiorze(z_2.nazwa_zmiennej())<<std::endl;

    return 0;
}
