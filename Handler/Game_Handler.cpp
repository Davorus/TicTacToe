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

void Game_Handler::set_players()
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
            Random_Bot* r = new Random_Bot();
            this->m_player.push_back(r);
        }
        if(temp == Player_Type::SmartBot)
        {
            Smart_Bot* s = new Smart_Bot();
            this->m_player.push_back(s);
        }
    }
}

void Game_Handler::start(Playfield_Handler* p_PH)
{
    this->set_players();
    
    Player_Type con_player_type;
    bool game_won = false;
    do
    {
        for(int i = 0; i < this->m_player.size(); i++)
        {
            if(this->m_playfield->check_playfield_full())
            {
                return;
            }

            this->m_playfield->print_Playfield();
            con_player_type = this->m_player.at(i)->get_player_type();
            if(con_player_type == Player_Type::Human)
            {
                this->m_player.at(i)->player_move(this->m_playfield);
            }
            if(con_player_type == Player_Type::RandomBot)
            {
                this->m_player.at(i)->player_move();
            }
            if(con_player_type == Player_Type::SmartBot)
            {
                this->m_player.at(i)->player_move();
            }
            
        }
    } while (game_won == false);
}