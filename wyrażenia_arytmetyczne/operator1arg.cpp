#include "operator1arg.hpp"
#include <cmath>

operator1arg::operator1arg(wyrazenie *l)
{
    this->l=l;
}

double sinus::oblicz()
{
    return sin(l->oblicz());
}

std::string sinus::zapis()
{
    return "sin("+l->zapis()+")";
}

double cosinus::oblicz()
{
    return cos(l->oblicz());
}

std::string cosinus::zapis()
{
    return "cos("+l->zapis()+")";
}

double ln::oblicz()
{
    return log(l->oblicz());
}

std::string ln::zapis()
{
    return "ln("+l->zapis()+")";
}

double wart_bezwz::oblicz()
{
    return abs(l->oblicz());
}

std::string wart_bezwz::zapis()
{
    return "|"+l->zapis()+"|";
}

double przeciwna::oblicz()
{
    return -l->oblicz();
}

std::string przeciwna::zapis()
{
    return "-("+l->zapis()+")";
}
