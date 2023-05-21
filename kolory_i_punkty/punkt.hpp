#include <iostream>
#include "kolor.hpp"

class punkt
{
public:
    double x=0, y=0;

public:
    punkt(){};
    punkt(double x, double y);
    double odleglosc(punkt a);
    static bool wspollinowe(punkt a, punkt b, punkt c);
};

class punktnazwany : public  virtual punkt
{
    std::string nazwa="";

public:
    void nazwij(std::string nazwa);
    std::string nazwa_pkt();
};


class punktkolorowy : public virtual punkt
{
    kolortransparentny k;

public:
    punktkolorowy(kolortransparentny k);
    kolortransparentny kolor_punktu();
};

class punktkolorowynazwany : public punktnazwany, public punktkolorowy
{
};

class wektor2d
{
public:
    wektor2d(double x,double y);
    double x,y;
};

class punkt2d : public punkt
{
public:
    punkt2d():punkt(){};
    punkt2d(double x, double y):punkt(x,y){};
    void transpozycja(wektor2d v);
};

class wektor3d
{
public:
    wektor3d(double  x,double y,double z);
    double x,y,z;
};

class punkt3d : public punkt2d
{
public:
    double z;
public:
    punkt3d(double  x,double y,double z);
    void transpozycja(wektor3d v);
    double odleglosc(punkt3d a);
    static bool wspollinowe(punkt3d a, punkt3d b, punkt3d c);
};


