#include <iostream>
#include "macierz.hpp"

using namespace obliczenia;

int main()
{
    wektor w1{1.62, 2.72, 3.14};
    std::cout<<"Wektor 1 : "<<w1<<"\n";
    std::cout<<"            w1[1] = "<<w1[1]<<"\n\n";
    wektor w2=w1;
    std::cout<<"Wektor 2 : "<<w2<<"\n";
    wektor w3(7);
    w3[3]=5.8;
    std::cout<<"Wektor 3 : "<<w3<<"\n";
    wektor w4(3);
    //std::cin>>w4;
    std::cout<<"Wektor 4 : "<<w4<<"\n\n";

    std::cout<<"-w1 : "<<-w1<<"\n";
    std::cout<<"w1 * 4 : "<<w1*4<<"\n";
    std::cout<<"w1 + w2 : "<<w1 + w2<<"\n";
    std::cout<<"w1 - w2 : "<<w1 - w2<<"\n";
    std::cout<<"w1 * w2 (iloczyn skalarny) : "<<w1 * w2<<"\n";

    w1+=w2;
    std::cout<<"w1 += w2 : "<<w1<<"\n";
    w1-=w2;
    std::cout<<"w1 -= w2 : "<<w1<<"\n";
    w1*=2;
    std::cout<<"w1 *= 2 : "<<w1<<"\n\n\n";


    macierz *m1=new macierz(2,3);
    (*m1)[1][1]=5;
    (*m1)[1][2]=1.5;
    std::cout<<"Macierz m1 : \n"<<*m1<<"\n";
    macierz *m2 = new macierz{{0, 1}, {1, 1}};
    std::cout<<"Macierz m2 : \n"<<*m2<<"\n";
    std::cout<<"m2[0][0] = "<<(*m2)[0][0]<<"\n\n";
    macierz *m3 = new macierz(*m2);
    std::cout<<"Macierz m3 : \n"<<*m3<<"\n";
    macierz *m4=new macierz(2,3);
    //std::cin>>*m4;
    std::cout<<"Macierz m4 : \n"<<*m4<<"\n";

    *m2 += *m3;
    std::cout<<"m2 += m3 :\n"<<*m2<<"\n";
    *m2 -= *m3;
    std::cout<<"m2 -= m3 :\n"<<*m2<<"\n";
    *m2 *= 0.2;
    std::cout<<"m2 *= 0.2 :\n"<<*m2<<"\n";

    std::cout<<"-m2 :\n"<<-(*m2)<<"\n";
    std::cout<<"~m1 (transpozycja) :\n"<<~(*m1)<<"\n";
    std::cout<<"m2 + m3 :\n"<<(*m2) + (*m3)<<"\n";
    std::cout<<"m2 - m3 :\n"<<(*m2) - (*m3)<<"\n";
    std::cout<<"m2 * m3 :\n"<<(*m2) * (*m3)<<"\n";

    return 0;
}
