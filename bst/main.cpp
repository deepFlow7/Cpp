#include <iostream>
#include <cstring>
#include "bst.hpp"
#include "errors.hpp"

template <typename T>
void tests(bst<T> *t)
{
    while(true)
    {
        std::string instruction;
        std::cin>>instruction;
        if (instruction.compare("end") == 0)
            return;
        T value;

        if (instruction.compare("bst_insert") != 0 && instruction.compare("bst_remove") != 0 && instruction.compare("bst_search") != 0)
            {
                if(instruction.compare("bst_print") == 0)
                    std::cout<<"     "<<*t<<"\n";
                else
                    std::cout<<"Incorrect instruction. Try again!\n";
            }
        else
        {
            std::cin>>value;
            if (instruction.compare("bst_insert") == 0)
                try
                {
                    t->bst_insert(value);
                }
                catch(InsertingDuplicateException e)
                {
                    std::cout<<"     Cannot insert duplicate value\n";
                }
            if (instruction.compare("bst_remove") == 0)
                try
                {
                    t->bst_remove(value);
                }
                catch(RemovingFromBstException e)
                {
                    std::cout<<"     Cannot remove - value is not in bst\n";
                }
            if (instruction.compare("bst_search") == 0)
                std::cout<<"     Is "<<value<<" in bst? "<<t->bst_search(value)<<"\n";
        }
    }
}

int main()
{
    bst<int> *b1 = new bst<int>();
    tests(b1);
    delete b1;
    return 0;
}
