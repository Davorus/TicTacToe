//----------------------------------------------------------------
#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_
//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
/*
    Über .hpp gelöst, da der Gnu Compiler keine Module auflösen kann und
    ich oft verwendete Befehle irgendwie auslagern wollte
*/

#include <iostream>
#include <conio.h>

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
}

#endif