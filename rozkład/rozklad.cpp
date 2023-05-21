#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int64_t> factorise(int64_t n)
{
     vector<int64_t> prime_factors;
    if((n==0) || (n==-1) || (n==1))
    {
        prime_factors.push_back(n);
        return prime_factors;
    }
    if(n<0)
        prime_factors.push_back(-1);
    int64_t divisor=2;
    while(n%divisor==0)
    {
        prime_factors.push_back(divisor);
        n=n/2;
    }
    divisor=3;
    while(divisor<=sqrt(abs(n)))
    {
        while(n%divisor==0)
        {
            prime_factors.push_back(divisor);
            n=n/divisor;
        }
        divisor+=2;
    }
    if(abs(n)!=1)
        prime_factors.push_back(abs(n));
    return prime_factors;
}
void print_factorisation(int64_t n,vector<int64_t> prime_factors)
{
    cout<<n<<"=";
    bool is_first=1;
    for(int64_t x:prime_factors)
    {
        if(!is_first)
            cout<<"*";
        cout<<x;
        is_first=0;
    }
    cout<<endl;
}
int main (int argc, char *argv[])
{
    if(argc==1)
        cerr<<"No arguments"<<endl;
    for(int i=1; i<argc; i++)
    {
        bool is_exception=0;
        int64_t n;
        try
        {
            n=stoll(argv[i]);
        }
        catch(invalid_argument &err)
        {
            cerr<<"Conversion failure ("<<argv[i]<<")"<<endl;
            is_exception=1;
        }
        if(!is_exception)
        {
            vector<int64_t> prime_factors=factorise(n);
            print_factorisation(n,prime_factors);
        }
    }
    return 0;
}
