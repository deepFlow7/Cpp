#include <iostream>
#include "kolejka.hpp"


void test(kolejka k)
{
    std::cout<<std::endl<<"Dlugosc : "<<k.dlugosc()<<std::endl;

    k.wstaw("pierwszy");
    k.wstaw("drugi");
    k.wstaw("trzeci");

    std::cout<<"Nowa dlugosc : "<<k.dlugosc()<<std::endl;
    std::cout<<"Pierwszy element k : "<<k.z_przodu()<<std::endl;
    std::cout<<"Ususwamy pierwszy element ("<<k.usun()<<")"<<std::endl;
    std::cout<<"Teraz kolejka ma dlugosc : "<<k.dlugosc()<<std::endl<<std::endl<<std::endl;
}

int main()
{

    kolejka k1,k2(5),k3{"pp","oo","ff"};
    kolejka k4=kolejka(kolejka(5));
    kolejka k5(k3);

    std::cout<<"Kolejka k1 (konstruktor domyslny - pojemnosc 1): "<<std::endl;
    test(k1);
    std::cout<<"Kolejka k2 (konstruktor z zadana pojemnoscia 5): "<<std::endl;
    test(k2);
    std::cout<<"Kolejka k3 (konstruktor z lista inicjalizacyjna {pp,oo,ff}) :"<<std::endl;
    test(k3);
    std::cout<<"Kolejka k4 (konstruktor przenoszacy) :"<<std::endl;
    test(k4);
    std::cout<<"Kolejka k5 (konstruktor kopiujacy kolejke k3) :"<<std::endl;
    test(k5);

    return 0;
}
