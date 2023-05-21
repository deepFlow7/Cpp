#include "operator2arg.hpp"
#include <cmath>

operator2arg::operator2arg(wyrazenie *l, wyrazenie *r):operator1arg(l)
{
    this->r=r;
}

double dodaj::oblicz()
{
    return l->oblicz()+r->oblicz();
}

std::string dodaj::zapis()
{
    return l->zapis()+"+"+r->zapis();
}

double odejmij::oblicz()
{
    return l->oblicz()-r->oblicz();
}

std::string odejmij::zapis()
{
    std::string z=l->zapis()+"-";
    if (typeid(*r) == typeid(dodaj))
        z+="("+r->zapis()+")";
    else
        z+=r->zapis();
    return z;
}

double mnoz::oblicz()
{
    return l->oblicz()*r->oblicz();
}

std::string mnoz::zapis()
{
    std::string z="";
    if (typeid(*l) == typeid(dodaj) || typeid(*l) == typeid(odejmij))
        z+="("+l->zapis()+")";
    else
        z+=l->zapis();
    z+="*";
    if (typeid(*r) == typeid(dodaj) || typeid(*r) == typeid(odejmij))
        z+="("+r->zapis()+")";
    else
        z+=r->zapis();
    return z;
}

double dziel::oblicz()
{
    if(r->oblicz()==0)
        throw "Dzielenie przez 0";
    return l->oblicz()/r->oblicz();
}

std::string dziel::zapis()
{
    std::string z="";
    if (typeid(*l) == typeid(dodaj) || typeid(*l) == typeid(odejmij))
        z+="("+l->zapis()+")";
    else
        z+=l->zapis();
    z+="/";
    if (typeid(*r) == typeid(dodaj) || typeid(*r) == typeid(odejmij) || typeid(*r) == typeid(mnoz) || typeid(*r) == typeid(dziel))
        z+="("+r->zapis()+")";
    else
        z+=r->zapis();
    return z;
}

double logarytm::oblicz()
{
    double podstawa=l->oblicz(), liczba=r->oblicz();
    if(podstawa<=0 || podstawa==1 || liczba<=0)
        throw "Niepoprawny logarytm";
    return log(liczba/podstawa);
}

std::string logarytm::zapis()
{
    return "log("+l->zapis()+","+r->zapis()+")";
}

double potega::oblicz()
{
    return pow(l->oblicz(),r->oblicz());
}

std::string potega::zapis()
{
    std::string z="";
    if (dynamic_cast<operator1arg*>(l) == nullptr)
        z+=l->zapis();
    else
        z+="("+l->zapis()+")";
    z+="^";
    if (dynamic_cast<operator1arg*>(r) == nullptr )
         z+=r->zapis();
    else
        z+="("+r->zapis()+")";
    return z;
}

double modulo::oblicz()
{
    if(r->oblicz()==0)
        throw "Modulo 0";
    return l->oblicz()-r->oblicz();
}

std::string modulo::zapis()
{
    std::string z="";
    if (typeid(*l) == typeid(dodaj) || typeid(*l) == typeid(odejmij) || typeid(*l) == typeid(mnoz) || typeid(*l) == typeid(dziel))
        z+="("+l->zapis()+")";
    else
        z+=l->zapis();
    z+="%";
    if (typeid(*r) == typeid(dodaj) || typeid(*r) == typeid(odejmij) || typeid(*r) == typeid(mnoz) || typeid(*r) == typeid(dziel))
        z+="("+r->zapis()+")";
    else
        z+=r->zapis();
    return z;
}




