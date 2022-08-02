//----------------------------------------------------------------
#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_
//----------------------------------------------------------------
#include <iostream>
#include <conio.h>
#include <unistd.h>
//----------------------------------------------------------------
//----------------------------------------------------------------
/*
    Some often used methods that are needed and simply reduced code
    by putting it in here
*/

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

    static void clear_screen()
    {
        std::cout << "\x1B[2J\x1B[H";
    }

    static void wait_for_enter()
    {
        getch();
    }

    static void sleep(float time)
    {
        sleep(time);
    }
}

#endif