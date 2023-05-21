#include <iostream>
#include "punkt.hpp"

int main()
{
    kolor k(12,50,100);
    std::cout<<"Kolor k :\n";
    std::cout<<"G : "<<k.get_g();
    k.set_b(20);
    std::cout<<", B : "<<k.get_b();
    k.przyciemnij_b(20);
    std::cout<<", przyciemnione B : "<<k.get_b();
    std::cout<<"\nSuma kolorow : "<<k.suma()<<std::endl<<std::endl;

    kolortransparentny k_t(20,20,20,100);
    k_t.ustaw_alfe(90);
    std::cout<<"Kolor k_t :\nAlfa : "<<k_t.get_alfa()<<std::endl<<std::endl;

    kolornazwany k_n;
    k_n.nazwij("czarny");
    std::cout<<"Kolor k_n :\nR : "<<k_n.get_r()<<", nazwa : "<<k_n.nazwa_koloru()<<std::endl<<std::endl;

    punkt p1, p2(1,1), p3(3,3);
    std::cout<<"P1 = ("<<p1.x<<", "<<p1.y<<")\n";
    std::cout<<"P2 = ("<<p2.x<<", "<<p2.y<<")\n";
    std::cout<<"P3 = ("<<p3.x<<", "<<p3.y<<")\n";
    std::cout<<"Czy wspolliniowe? "<<punkt::wspollinowe(p1,p2,p3)<<std::endl;
    std::cout<<"Odleglosc miedzy p1 i p2 : "<<p1.odleglosc(p2)<<std::endl<<std::endl;

    punktnazwany p_n;
    p_n.nazwij("Zerowy");
    std::cout<<"P_n = ("<<p_n.x<<", "<<p_n.y<<"), nazwa : "<<p_n.nazwa_pkt()<<std::endl<<std::endl;

    punktkolorowy p_k(k_t);
    std::cout<<"P_k :\nAlfa : "<<p_k.kolor_punktu().get_alfa()<<std::endl<<std::endl;

    punkt2d p_2d(2,1);
    p_2d.transpozycja(wektor2d(3,-5));
    std::cout<<"P_2d = ("<<p_2d.x<<", "<<p_2d.y<<")"<<std::endl<<std::endl;

    punkt3d p1_3d(1,2,3), p2_3d(2,3,6), p3_3d(0,0,0);
    p1_3d.transpozycja(wektor3d(1,-1,3.4));
    std::cout<<"P1_3d = ("<<p1_3d.x<<", "<<p1_3d.y<<", "<<p1_3d.z<<")\n";
    std::cout<<"Czy wspolliniowe? "<<punkt3d::wspollinowe(p1_3d,p2_3d,p3_3d)<<std::endl;
    std::cout<<"Odleglosc miedzy p1_3d i p2_3d : "<<p1_3d.odleglosc(p2_3d)<<std::endl<<std::endl;

    return 0;
}
