#include <list>

class kolejka
{
    int pojemnosc, poczatek = 0, ile = 0;
    std::string *tab;

public:
    kolejka();
    kolejka(int pojemnosc);
    kolejka(std::initializer_list<std::string> l);
    kolejka(kolejka &k);
    kolejka& operator= (kolejka &k);
    kolejka(kolejka &&k);
    kolejka& operator= (kolejka &&k);
    ~kolejka();

public:
    void wstaw(std::string s);
    std::string usun();
    std::string z_przodu();
    int dlugosc();
};
