#include "operator1arg.hpp"

class operator2arg : public operator1arg
{
protected:
    wyrazenie *r;
public:
    operator2arg(wyrazenie *l, wyrazenie *r);
};

class dodaj : public operator2arg
{
public:
    dodaj(wyrazenie *l,wyrazenie *r):operator2arg(l,r){};
    double oblicz() override;
    std::string zapis() override;
};

class odejmij : public operator2arg
{
public:
    odejmij(wyrazenie *l,wyrazenie *r):operator2arg(l,r){};
    double oblicz() override;
    std::string zapis() override;
};

class mnoz : public operator2arg
{
public:
    mnoz(wyrazenie *l,wyrazenie *r):operator2arg(l,r){};
    double oblicz() override;
    std::string zapis() override;
};

class dziel : public operator2arg
{
public:
    dziel(wyrazenie *l,wyrazenie *r):operator2arg(l,r){};
    double oblicz() override;
    std::string zapis() override;
};

class logarytm : public operator2arg
{
public:
    logarytm(wyrazenie *l,wyrazenie *r):operator2arg(l,r){};
    double oblicz() override;
    std::string zapis() override;
};

class potega : public operator2arg
{
public:
    potega(wyrazenie *l,wyrazenie *r):operator2arg(l,r){};
    double oblicz() override;
    std::string zapis() override;
};

class modulo : public operator2arg
{
public:
    modulo(wyrazenie *l,wyrazenie *r):operator2arg(l,r){};
    double oblicz() override;
    std::string zapis() override;
};
