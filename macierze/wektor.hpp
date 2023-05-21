#include "errors.hpp"

namespace obliczenia
{
    class wektor
    {
        double *tab = nullptr;
        const int k;

    public :
        wektor(int k);
        wektor(wektor &w);
        wektor(std::initializer_list<double> l);
        ~wektor();
        friend int rozmiar(const wektor *w);
        wektor& operator = (const wektor &w);
        wektor& operator = (wektor &&w);
        friend wektor operator-(const wektor &v);
        friend wektor operator+(const wektor &x, const wektor &y);
        friend wektor operator-(const wektor &x, const wektor &y);
        friend wektor operator*(const wektor &v, double d);
        friend wektor operator*(double d, const wektor &v);
        friend double operator*(const wektor &x, const wektor &y);
        wektor& operator+=(const wektor &v);
        wektor& operator-=(const wektor &v);
        wektor& operator*=(double d);
        double  operator[](int i) const;
        double& operator[](int i);
        friend std::istream & operator >> (std::istream &we, wektor &v);
        friend std::ostream & operator << (std::ostream &wy, const wektor &v);
    };
}
