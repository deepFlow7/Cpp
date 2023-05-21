class zbior_zmiennych{
    const int n;
    zmienna *tab;
public:
    zbior_zmiennych(int rozmiar);
    ~zbior_zmiennych();
public:
    void wstaw_do_zbioru(zmienna z);
    bool czy_w_zbiorze(std::string nazwa_zmiennej);
    void usun_ze_zbioru(std::string nazwa_zmiennej);
    double wartosc_zmiennej(std::string nazwa_zmiennej);
    void zmien_wartosc_zmiennej(std::string nazwa_zmiennej, double nowa_wartosc);
};
