#include <math.h>
#include "punkt.hpp"

punkt::punkt(double x, double y)
{
    this->x=x;
    this->y=y;
}

double punkt::odleglosc(punkt a)
{
    return sqrt(pow(this->x-a.x,2)+pow(this->y-a.y,2));
}

bool punkt::wspollinowe(punkt a, punkt b, punkt c)
{
    double wsp;
    if(a.x==c.x)
    {
        if(b.x==a.x)
            return true;
        else
            return false;
    }
    wsp=(a.x-b.x)/(a.x-c.x);
    return a.y-b.y==(a.y-c.y)*wsp;
}

bool litera(char x)
{
    if((x>='a' && x<='z') || (x>='A' && x<='Z'))
        return true;
    return false;
}

void punktnazwany::nazwij(std::string nazwa)
{
    if(nazwa!="" && !litera(nazwa[0]))
        throw "Nieprawidlowa nazwa punktu";
    for(uint32_t i=1;i<nazwa.size();i++)
        if(!litera(nazwa[i]) && (nazwa[i]>'0' || nazwa[i]<'9'))
            throw "Nieprawidlowa nazwa koloru";
    this->nazwa=nazwa;
}

std::string punktnazwany::nazwa_pkt()
{
    return nazwa;
}

punktkolorowy::punktkolorowy(kolortransparentny k)
{
    this->k=k;
}

kolortransparentny punktkolorowy::kolor_punktu()
{
    return k;
}

wektor2d::wektor2d(double x,double y)
{
    this->x=x;
    this->y=y;
}

void punkt2d::transpozycja(wektor2d v)
{
    x+=v.x;
    y+=v.y;
}

wektor3d::wektor3d(double  x,double y,double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

punkt3d::punkt3d(double  x,double y,double z)
{
    this->x=x;
    this->y=y;
    this->z=z;
}

void punkt3d::transpozycja(wektor3d v)
{
    x+=v.x;
    y+=v.y;
    z+=v.z;
}

double punkt3d::odleglosc(punkt3d a)
{
    return sqrt(pow(this->x-a.x,2) + pow(this->y-a.y,2) + pow(this->z-a.z,2));
}

bool punkt3d::wspollinowe(punkt3d a, punkt3d b, punkt3d c)
{
    if((a.odleglosc(c) == a.odleglosc(b) + b.odleglosc(c)) || (a.odleglosc(c) == a.odleglosc(b) - b.odleglosc(c)))
        return true;
    return false;
}
