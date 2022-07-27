#include <iostream>

#include "Game_Handler.hpp"
#include "Gamesetup_Handler.hpp"

int main()
{
    Game_Handler gh;
    Gamesetup_Handler h(gh);
    h.print_Start_Menu();
}
