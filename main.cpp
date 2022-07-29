#include <iostream>

#include "Game_Handler.hpp"
#include "Gamesetup_Handler.hpp"
#include "Utilities.hpp"
#include "Playfield_Handler.hpp"
#include "Human_Player.hpp"

int main()
{
    /*
    Gamesetup_Handler h;
    h.print_Start_Menu();
    */
    Playfield_Handler* ph = new Playfield_Handler();
    ph->initialize_Playfield(5,5);
    Human_Player hp(ph, 1);
}
