#include <iostream>
#include "tabbit.hpp"

using namespace obliczenia;

int main()
{
    tabbit t1(8);
    tabbit t2((uint64_t)45ull);
    tabbit t3(t2);
    tabbit t4(tabbit(71));

    std::cout << "t1 : "<< t1 << std::endl;
    std::cout << "t2 : "<< t2 << std::endl;
    std::cout << "t3 : "<< t3 << std::endl;
    std::cout << "t4 : "<< t4 << std::endl;

    tabbit t5(0);
    //std::cin>>t5;
    std::cout << "t5 : " << t5 << "\n\n";

    t3=t1;
    std::cout << "t3 = t1 : "<< t3 << std::endl;

    t3=tabbit(15);
    std::cout << "t3 = tabbit(15) : " << t3 << "\n\n";

    t3[1]=1;
    t3[3]=1;
    t3[5]=1;
    std::cout << "t3[3] = " << t3[3].czytaj() << std::endl;
    t3[3]=0;
    std::cout << "t3 ze zmienionymi bitami : " << t3 << "\n\n";

    tabbit arg1((uint64_t)17ull);
    tabbit arg2((uint64_t)57ull);
    std::cout << "arg1 :        " << arg1 << std::endl;
    std::cout << "!arg1 :       " << (!arg1) << std::endl;
    std::cout << "arg2 :        " << arg2 << std::endl;
    std::cout << "arg1 | arg2 : " << (arg1 | arg2) << std::endl;
    std::cout << "arg1 & arg2 : " << (arg1 & arg2) << std::endl;
    std::cout << "arg1 ^ arg2 : " << (arg1 ^ arg2) << "\n\n";

    tabbit tab_or((uint64_t)31ull);
    std::cout << "arg1 :           " << arg1 << std::endl;
    std::cout << "tab_or :         " << tab_or << std::endl;
    tab_or |= arg1;
    std::cout << "tab_or |= arg1 : " << tab_or << "\n\n";

    tabbit tab_and((uint64_t)23ull);
    std::cout << "arg1 :            " << arg1 << std::endl;
    std::cout << "tab_and :         " << tab_and << std::endl;
    tab_and &= arg1;
    std::cout << "tab_and &= arg1 : " << tab_and << "\n\n";

    tabbit tab_xor((uint64_t)31ull);
    std::cout << "arg1 :            " << arg1 << std::endl;
    std::cout << "tab_xor :         " << tab_xor << std::endl;
    tab_xor ^= arg1;
    std::cout << "tab_xor ^= arg1 : " << tab_xor << std::endl;

    return 0;
}
