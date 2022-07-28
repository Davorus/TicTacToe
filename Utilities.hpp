#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_

#include <iostream>

namespace MyUtils
{
    template <class T>
    static void print(T &p_input)
    {
        std::cout << p_input << std::endl;
    }

    template <class T>
    static void input(T &input)
    {
        print("Enter value:");
        std::cin >> input;
    }
}

#endif