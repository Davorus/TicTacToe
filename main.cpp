//----------------------------------------------------------------
#include <iostream>
//----------------------------------------------------------------
#include "Handler/Gamesetup_Handler.hpp"
#include "Utilities.hpp"
//----------------------------------------------------------------

int main()
{
    /*
        My idea behind this while loop is that the game itself
        should start completely new, so that the game can run
        hopefully bug free
    */
    bool exit = false;
    while (exit == false)
    {
        Gamesetup_Handler h;
        h.print_start_menu();
        
        MyUtils::clear_screen();
        MyUtils::print("Do you want to leave the game?");
        MyUtils::print("\t1: Yes");
        MyUtils::print("\t2: No");
        
        int user_input = 0;
        MyUtils::input(user_input);
        if (user_input == 1)
        {
            exit = true;
        }
    }
}
