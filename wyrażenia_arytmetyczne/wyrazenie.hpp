#include <vector>
#include <string>

class wyrazenie
{
public:
    virtual double oblicz()=0;
    virtual std::string zapis()=0;
    wyrazenie& operator = (const wyrazenie &w) = delete;
    wyrazenie& operator = (wyrazenie &&w) = delete;
};

class liczba : public wyrazenie
{
    double x;
public:
    liczba(double x);
    double oblicz() override;
    std::string zapis() override;
};

class zmienna : public wyrazenie
{
    std::string nazwa;
    static std::vector<std::pair<std::string, double>> zbior_zmiennych;
public:
    zmienna(std::string nazwa);
    static void dodaj_do_zbioru(std::pair<std::string, double> p);
    static void usun_ze_zbioru(std::string nazwa_zmiennej);
    static void modyfikuj_zmienna_w_zbiorze(std::string nazwa_zmiennej, double nowa_wartosc);
    double oblicz() override;
    std::string zapis() override;
};

class stala : public wyrazenie
{
    std::string nazwa;
    double wartosc;
public:
    stala(std::string nazwa, double wartosc);
    double oblicz() override;
    std::string zapis() override;
};

class pi : public stala
{
public:
    pi():stala("pi",3.14){};
};

class e : public stala
{
public:
    e():stala("e",2.72){};
};

class fi : public stala
{
public:
    fi():stala("pi",1.61){};
};
