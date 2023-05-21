#include <iostream>

namespace obliczenia
{
    class tabbit
    {
        typedef uint64_t slowo;
        static const int rozmiarSlowa;
        friend std::istream & operator >> (std::istream &we, tabbit &tb);
        friend std::ostream & operator << (std::ostream &wy, const tabbit &tb);
        class ref
        {
            int i;
            uint64_t *tab;
            public:
                ref(){};
                ref(int i,uint64_t* tab){this->i=i; this->tab=tab;};
                bool czytaj_bit(int i,uint64_t *tab);
                void ustaw_bit(int i,uint64_t *tab,bool wartosc);
                bool czytaj();
                ref& operator = (bool b){this->ustaw_bit(i,tab,b);
                return *this;};
        };
    protected:
        int dl;
        slowo *tab;
    public:
        explicit tabbit(int rozm);
        explicit tabbit(slowo tb);
        ~tabbit();
        tabbit(const tabbit &tb);
        tabbit(tabbit &&tb);
        tabbit& operator = (const tabbit &tb);
        tabbit& operator = (tabbit &&tb);
    private:
        bool czytaj(int i) const;
        void pisz(int i, bool b);
    public:
        bool operator [] (int i) const;
        ref operator [] (int i);
        inline int rozmiar() const;
    public:
        tabbit operator | (tabbit &tb);
        void operator |= (tabbit &tb);
        tabbit operator & (tabbit &tb);
        void operator &= (tabbit &tb);
        tabbit operator ^ (tabbit &tb);
        void operator ^= (tabbit &tb);
        tabbit operator ! ();
    };
}
