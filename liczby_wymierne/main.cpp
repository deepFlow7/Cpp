#include <iostream>
#include "wymierna.hpp"

using namespace obliczenia;

int main()
{
    wymierna w1(1,7), w2(5,12), d_w(5.75);

    std::cout << "Double 5.75 na wymierną : " << d_w.licznik() << " / " << d_w.mianownik() << "\n\n";
    std::cout << "Wymierna 1 (double) : " << (double)w1 << "\n";
    std::cout << "Wymierna 1 (zaokrąglona do całkowitej) : " << (int)w1 << "\n";
    std::cout << "Wymierna 1 (z rozwinięciem okresowym) : " << w1 << "\n\n";

    std::cout << "w1 = " << w1.licznik() << " / " << w1.mianownik() << "\n";
    std::cout << "w2 = " << w2.licznik() << " / " << w2.mianownik() << "\n\n";

    wymierna w3 = w1 + w2;
    std::cout << "w1 + w2 = " << w3.licznik() << " / " << w3.mianownik() << "\n";

    w3 = w1 - w2;
    std::cout << "w1 - w2 = " << w3.licznik() << " / " << w3.mianownik() << "\n";

    w3 = w1 * w2;
    std::cout << "w1 * w2 = " << w3.licznik() << " / " << w3.mianownik() << "\n";

    w3 = w1 / w2;
    std::cout << "w1 / w2 = " << w3.licznik() << " / " << w3.mianownik() << "\n\n";

    w1 = -w1;
    std::cout << "-w1 = " << w1.licznik() << " / " << w1.mianownik() << "\n";

    w2 = !w2;
    std::cout << "(odwrotność) !w2 = " << w2.licznik() << " / " << w2.mianownik() << "\n";

    return 0;
}
