module;
#include <iostream>

export namespace GUI
{
    template <class T>
    void print(T input)
    {
        std::cout << input << std::endl;
    }
}