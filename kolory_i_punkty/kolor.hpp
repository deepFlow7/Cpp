#include <iostream>

class kolor
{
    int r,g,b;

public:
    kolor();
    kolor(int r, int g, int b);

public:
    int get_r();
    void set_r(int n);
    int get_g();
    void set_g(int n);
    int get_b();
    void set_b(int n);
    void rozjasnij_r(int i);
    void przyciemnij_r(int i);
    void rozjasnij_g(int i);
    void przyciemnij_g(int i);
    void rozjasnij_b(int i);
    void przyciemnij_b(int i);
    int suma();

};

class kolortransparentny : public kolor
{
    int alfa=255;

public:
    kolortransparentny():kolor() {};
    kolortransparentny(int r,int g,int b,int alfa);
    void ustaw_alfe(int a);
    int get_alfa();
};

class kolornazwany : public kolortransparentny
{
    std::string nazwa="";

public:
    kolornazwany():kolortransparentny(){};
    void nazwij(std::string nazwa);
    std::string nazwa_koloru();
};
