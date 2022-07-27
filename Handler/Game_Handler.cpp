//----------------------------------------------------------------
#include <iostream>
//----------------------------------------------------------------
#include "Game_Handler.hpp"
//----------------------------------------------------------------

Game_Handler::Game_Handler()
{
}

void Game_Handler::start(int p_Player_Amount, Bot_Type bot1) const
{
    std::cout << "Zwei Spieler Modus" << std::endl;
}

void Game_Handler::start(int p_Player_Amount, Bot_Type bot1, Bot_Type bot2) const
{
    std::cout << "Drei Spieler Modus" << std::endl;
}