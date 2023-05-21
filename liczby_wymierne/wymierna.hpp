#include <ostream>

namespace obliczenia
{
    class wymierna
    {
        int licz, mian;
    public :
        wymierna(int licz, int mian) noexcept(false);
        wymierna(int liczba) noexcept : wymierna(liczba, 1) {} ;
        wymierna(double x) noexcept(false);
        ~wymierna() noexcept;
        int licznik() noexcept;
        int mianownik() noexcept;
        wymierna operator + (wymierna w) noexcept(false);
        wymierna operator - (wymierna w) noexcept(false);
        wymierna operator * (wymierna w) noexcept(false);
        wymierna operator / (wymierna w) noexcept(false);
        wymierna operator - () noexcept(false);
        wymierna operator ! () noexcept(false);
        operator double () noexcept;
        operator int () noexcept;
        friend std::ostream& operator<< (std::ostream &wyj, const wymierna &w) noexcept;
    };
}
