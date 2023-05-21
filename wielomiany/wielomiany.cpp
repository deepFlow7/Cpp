#include "wielomiany.hpp"
#include <list>

wielomian::wielomian ()
{
    n=0;
    a=new double[n+1];
    a[0]=1.0;
}

wielomian::wielomian (int st, const double wsp[])
{
    if(st<0)
        throw "Stopien wielomianu nie moze byc ujemny";
    if(st!=0 && wsp[st]==0)
        throw "Wspolczynnik przy najwyzszej potedze nie moze byc rowny 0";
    n=st;
    a=new double[n+1];
    std::copy(wsp,wsp+n+1,a);
}

wielomian::wielomian (std::initializer_list<double> wsp)
{
    if(wsp.size()==0)
        throw "Stopien wielomianu nie moze byc ujemny";
    if(wsp.size()!=1 && *(wsp.end()-1)==0)
        throw "Wspolczynnik przy najwyzszej potedze nie moze byc rowny 0";
    n=wsp.size()-1;
    a=new double[n+1];
    std::copy(wsp.begin(), wsp.end(), a);
}

wielomian::wielomian (const wielomian &w):wielomian(w.n,w.a)
{
}

wielomian::wielomian (wielomian &&w):wielomian(w.n,w.a)
{
    delete[] w.a;
    w.a=nullptr;
}

wielomian& wielomian::operator = (const wielomian &w)
{
    if (this != &w)
    {
        delete[] a;
        n=w.n;
        a=new double[n+1];
        std::copy(w.a,w.a+n+1,a);
    }
    return *this;
}

wielomian& wielomian::operator = (wielomian &&w)
{
    if (this != &w)
    {
        delete[] a;
        n=w.n;
        a=new double[n+1];
        std::copy(w.a,w.a+n+1,a);
        delete[] w.a;
        w.a=nullptr;
    }
    return *this;
}

wielomian::~wielomian ()
{
    delete[] a;
}

int wielomian::stopien_wielomianu()
{
    return n;
}

std::istream& operator >> (std::istream &we, wielomian &w)
{
    int n;
    we>>n;
    if(n<0)
        throw "Stopien wielomianu nie moze byc ujemny";
    w.n=n;
    delete[] w.a;
    w.a=new double[w.n+1];
    for(int i=0; i<=w.n; i++)
        we>>w.a[i];
    return we;
}

std::ostream& operator << (std::ostream &wy, const wielomian &w)
{
    wy<<"stopien : "<<w.n<<", wspolczynniki : ";
    for(int i=0; i<=w.n; i++)
    {
        wy<<w.a[i];
        if(i!=w.n)
            wy<<", ";
    }
    wy<<std::endl;
    return wy;
}

wielomian operator + (const wielomian &u, const wielomian &v)
{
    int st=std::max(u.n,v.n);
    double *wsp=new double[st+1];
    for(int i=0; i<=st; i++)
        wsp[i]=u.a[i]+v.a[i];
    while(wsp[st]==0 && st>0)
        st--;
    return wielomian(st,wsp);
}

wielomian operator - (const wielomian &u, const wielomian &v)
{
    int st=std::max(u.n,v.n);
    double *wsp=new double[st+1];
    for(int i=0; i<=st; i++)
        wsp[i]=u.a[i]-v.a[i];
     while(wsp[st]==0 && st>0)
        st--;
    return wielomian(st,wsp);
}

wielomian operator * (const wielomian &u, const wielomian &v)
{
    if((u.n==0 && u[0]==0) || (v.n==0 && v[0]==0))
    {
        wielomian zerowy;
        zerowy[0]=0;
        return zerowy;
    }
    int st=u.n+v.n;
    double *wsp=new double[st+1];
    for(int i=0; i<=st; i++)
        wsp[i]=0;
    for(int i=0; i<=u.n; i++)
        for(int j=0; j<=v.n; j++)
            wsp[i+j]+=u.a[i]*v.a[j];
    return wielomian(st,wsp);
}

wielomian operator * (double c, const wielomian &v)
{
    if(c==0)
    {
        wielomian zerowy;
        zerowy[0]=0;
        return zerowy;
    }
    int st=v.n;
    double *wsp=new double[st+1];
    for(int i=0; i<=st; i++)
        wsp[i]=v.a[i]*c;
    return wielomian(st,wsp);
}

wielomian& wielomian::operator += (const wielomian &v)
{
    const wielomian w=*this;
    *this=w+v;
    return *this;
}

wielomian& wielomian::operator -= (const wielomian &v)
{
    const wielomian w=*this;
    *this=w-v;
    return *this;
}

wielomian& wielomian::operator *= (const wielomian &v)
{
    const wielomian w=*this;
    *this=w*v;
    return *this;
}

wielomian& wielomian::operator *= (double c)
{
    const wielomian w=*this;
    *this=c*w;
    return *this;
}

double wielomian::operator () (double x) const
{
    double wart=0;
    for(int i=n; i>=0; i--)
        wart=wart*x+a[i];
    return wart;
}

double wielomian::operator [] (int i) const
{
    return a[i];
}

double& wielomian::operator [] (int i)
{
    return a[i];
}

