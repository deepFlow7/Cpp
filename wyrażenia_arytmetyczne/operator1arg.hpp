#include "wyrazenie.hpp"

class operator1arg : public wyrazenie
{
protected:
    wyrazenie *l;
public:
    operator1arg(wyrazenie *l);
};

class sinus : public operator1arg
{
public:
    sinus(wyrazenie *l):operator1arg(l){};
    double oblicz() override;
    std::string zapis() override;
};

class cosinus : public operator1arg
{
public:
    cosinus(wyrazenie *l):operator1arg(l){};
    double oblicz() override;
    std::string zapis() override;
};

class ln : public operator1arg
{
public:
    ln(wyrazenie *l):operator1arg(l){};
    double oblicz() override;
    std::string zapis() override;
};

class wart_bezwz : public operator1arg
{
public:
    wart_bezwz(wyrazenie *l):operator1arg(l){};
    double oblicz() override;
    std::string zapis() override;
};

class przeciwna : public operator1arg
{
public:
    przeciwna(wyrazenie *l):operator1arg(l){};
    double oblicz() override;
    std::string zapis() override;
};



