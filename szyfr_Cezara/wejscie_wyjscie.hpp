#include <fstream>

class wejscie
{
    std::ifstream we;

public :
    wejscie(std::string nazwa);
    ~wejscie();
    bool koniec_pliku();
    std::string nast_linia();
};

class wyjscie
{
    std::ofstream wy;

public :
    wyjscie(std::string nazwa);
    ~wyjscie();
    void pisz_linie(std::string linia);
};
