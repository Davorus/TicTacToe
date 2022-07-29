//----------------------------------------------------------------
#include <iostream>
//----------------------------------------------------------------
#include "Game_Handler.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

Game_Handler::Game_Handler()
{
}

void Game_Handler::set_players(Player_Type type)
{
    this->to_be_set_players.push_back(type);
}

void Game_Handler::start() const
{

}