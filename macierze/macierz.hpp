#include "wektor.hpp"

namespace obliczenia
{
    class macierz
    {
        wektor **tab = nullptr;
        const int w, k;

    public :
        macierz(int w, int k);
        macierz(macierz &m);
        macierz(std::initializer_list<wektor> l);
        ~macierz();
        macierz& operator = (const macierz &m);
        macierz& operator = (macierz &&m);
        friend macierz& operator-(const macierz &m);
        friend macierz& operator+(const macierz &p, const macierz &q);
        friend macierz& operator-(const macierz &p, const macierz &q);
        friend macierz& operator*(const macierz &m, double d);
        friend macierz& operator*(double d, const macierz &m);
        friend macierz& operator*(const macierz &p, const macierz &q);
        friend macierz& operator~(const macierz &m);
        macierz& operator+=(const macierz &m);
        macierz& operator-=(const macierz &m);
        macierz& operator*=(double d);
        wektor  operator[](int i) const;
        wektor& operator[](int i);
        friend std::istream & operator >> (std::istream &we, macierz &m);
        friend std::ostream & operator << (std::ostream &wy, const macierz &m);
    };
}
