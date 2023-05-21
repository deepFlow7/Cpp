#include <iostream>
#include "wielomiany.hpp"

int main()
{
    std::cout<<"Wspolczynniki podawane sa od tych przy najmniejszych potegach x do tych przy najwiekszych\n\n";

    wielomian w_1;
    double t[5]={1,2.9,3.1,4,5};
    wielomian w_2(4,t), w_3({1,2.0,3,4.5,5,6.1,7});
    wielomian w_4(w_2), w_5(wielomian({2.2,9,9}));

    std::cout<<"Wielomian w_1 : \n   "<<w_1;
    std::cout<<"Wielomian w_2 : \n   "<<w_2;
    std::cout<<"Wielomian w_3 : \n   "<<w_3;
    std::cout<<"Wielomian w_4 : \n   "<<w_4;
    std::cout<<"Wielomian w_5 : \n   "<<w_5<<std::endl;

    w_5=w_1;
    std::cout<<"Wielomian w_5 po przypisaniu kopiujacym (w_1) : \n   "<<w_5;
    w_5=wielomian({9.8,8,7});
    std::cout<<"Wielomian w_5 po przypisaniu przenoszacym : \n   "<<w_5;

    wielomian w_6;
    std::cout<<"\nPodaj stopien i wspolczynniki wielomianu :\n";
    //std::cin>>w_6;
    std::cout<<"Wielomian w_6 :\n"<<w_6<<std::endl;

    wielomian v({2,1,7,-1.1});
    wielomian w({0,2,1.7,-7});
    std::cout<<"Wielomian v: \n   "<<v;
    std::cout<<"Wielomian w : \n   "<<w;
    std::cout<<"Wielomian v + w : \n   "<<v + w;
    std::cout<<"Wielomian v - w : \n   "<<v - w;
    std::cout<<"Wielomian v * w : \n   "<<v * w;
    std::cout<<"Wielomian 5 * w : \n   "<<5 * w;

    wielomian x({5, 7, -2.7,1});
    std::cout<<"\nWielomian x: \n   "<<x;
    x+=w;
    std::cout<<"Wielomian x += w : \n   "<<x;
    x-=w;
    std::cout<<"Wielomian x -= w : \n   "<<x;
    x*=w;
    std::cout<<"Wielomian x *= w : \n   "<<x;
    x*=4;
    std::cout<<"Wielomian x *= 4 : \n   "<<x;

    wielomian z=wielomian({1,-2.5,8});
    std::cout<<"\nWielomian z : \n   "<<z;
    std::cout<<"Wartosc z w 0.5 : "<<z(0.5)<<std::endl;
    std::cout<<"Zerowy i pierwszy wspolczynnik z : "<<z[0]<<", "<<z[1]<<std::endl;
    z[0]=3;
    std::cout<<"Nowy zerowy wspolczynnik z : "<<z[0]<<std::endl;

    return 0;
}
