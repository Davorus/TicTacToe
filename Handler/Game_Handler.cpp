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
    this->m_to_be_set_players.push_back(type);
}

void Game_Handler::initialize_players()
{
    for(int i = 0; i < this->m_to_be_set_players.size(); i++)
    {
        Player_Type temp = this->m_to_be_set_players.at(i);
        if(temp == Player_Type::Human)
        {
            Human_Player* h = new Human_Player(i+1);
            this->m_player.push_back(h);
        }
        if(temp == Player_Type::RandomBot)
        {
            Random_Bot* r = new Random_Bot(i+1);
            this->m_player.push_back(r);
        }
        if(temp == Player_Type::SmartBot)
        {
            Smart_Bot* s = new Smart_Bot(i+1);
            this->m_player.push_back(s);
        }
    }
}

void Game_Handler::start(Playfield_Handler* p_PH)
{
    this->initialize_players();
    
    bool game_won = false;
    do
    {
        p_PH->print_Playfield();
        bool player_legal_move = false;
        for(int i = 0; i < this->m_player.size(); i++)
        {    
            do
            {
                player_legal_move = this->m_player.at(i)->player_move(p_PH);
                p_PH->print_Playfield();
            } while (player_legal_move == false);
            
            if(p_PH->check_playfield_full())
            {
                return;
            }
        }
    } while (game_won == false);
}
