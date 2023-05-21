#include <list>
#include <iostream>

class wielomian
{
    int n;
    double *a;

public:
    wielomian ();
    wielomian (int st, const double wsp[]);
    wielomian (std::initializer_list<double> wsp);
    wielomian (const wielomian &w);
    wielomian (wielomian &&w);
    wielomian& operator = (const wielomian &w);
    wielomian& operator = (wielomian &&w);
    ~wielomian ();

public:
    int stopien_wielomianu();

public:
    friend std::istream& operator>> (std::istream &we, wielomian &w);
    friend std::ostream& operator << (std::ostream &wy, const wielomian &w);

public:
    friend wielomian operator + (const wielomian &u, const wielomian &v);
    friend wielomian operator - (const wielomian &u, const wielomian &v);
    friend wielomian operator * (const wielomian &u, const wielomian &v);
    friend wielomian operator * (double c, const wielomian &v);
    wielomian& operator += (const wielomian &v);
    wielomian& operator -= (const wielomian &v);
    wielomian& operator *= (const wielomian &v);
    wielomian& operator *= (double c);
    double operator () (double x) const;
    double operator [] (int i) const;
    double& operator [] (int i);

};
