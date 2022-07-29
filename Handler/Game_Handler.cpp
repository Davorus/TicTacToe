//----------------------------------------------------------------
#include <iostream>
//----------------------------------------------------------------
#include "Game_Handler.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

Game_Handler::Game_Handler()
{
}

void Game_Handler::get_players(Player_Type type)
{
    this->m_to_be_set_players.push_back(type);
}

void Game_Handler::set_players()
{
    for(int i = 0; i < this->m_to_be_set_players.size(); i++)
    {
        Player_Type temp = this->m_to_be_set_players.at(i);
        if(temp == Player_Type::Human)
        {
            Human_Player* h = new Human_Player(i);
            this->m_human.push_back(h);
        }
        if(temp == Player_Type::RandomBot)
        {
            Random_Bot* r = new Random_Bot();
            this->m_bots.push_back(r);
        }
        if(temp == Player_Type::SmartBot)
        {
            Smart_Bot* s = new Smart_Bot();
            this->m_bots.push_back(s);
        }
    }
}

void Game_Handler::start(Playfield_Handler* p_PH)
{
    this->set_players();
    
    for(int i = 0; i < this->m_human.size(); i++)
    {
        this->m_human.at(i)->set_playfield(p_PH);
    }

    p_PH->print_Playfield();
    int playermoves = 0;
    do
    {
        this->m_human.at(0)->player_move();
        
        MyUtils::print("Parameter Spieldfeld:");
        p_PH->print_Playfield();
        MyUtils::print("");

        h->print_playfield();
        MyUtils::print("");

        playermoves++;
    } while (playermoves < 5);
}