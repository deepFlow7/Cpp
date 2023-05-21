class zmienna{
    std::string nazwa;
    double wartosc;
public:
    zmienna():nazwa("_"){};
    zmienna(std::string nazwa);
    zmienna(std::string nazwa, double wartosc);
public:
    std::string nazwa_zmiennej();
    double wartosc_zmiennej();
    void ustaw_wartosc_zmiennej(double wartosc);
};
