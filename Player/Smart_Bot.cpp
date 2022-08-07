//----------------------------------------------------------------
#include <random>
#include <iostream>
//----------------------------------------------------------------
#include "Smart_Bot.hpp"
//----------------------------------------------------------------

/*
    His instance number in creation is his marking on the playfield
*/
Smart_Bot::Smart_Bot(int stone)
    :m_stone{stone}
    ,first_move_made{false}
{
}

Player_Type Smart_Bot::get_player_type()
{
    return Player_Type::SmartBot;
}

bool Smart_Bot::check_horizontal_move(Playfield_Handler* p_PH)
{
    if(this->x_pos < p_PH->get_rows())
    {
        if (p_PH->m_playfield.at(this->y_pos).at(this->x_pos+1) == 0)
        {
            this->x_pos = x_pos+1;
            p_PH->player_move(this->y_pos, this->x_pos, this->m_stone);
            return true;
        }
    }
    
    if(this->x_pos == p_PH->get_rows())
    {
        if (p_PH->m_playfield.at(this->y_pos).at(this->x_pos-1) == 0)
        {
            this->x_pos = x_pos-1;
            p_PH->player_move(this->y_pos, this->x_pos, this->m_stone);
            return true;
        }
    }

    return false;
}

bool Smart_Bot::player_move(Playfield_Handler* p_PH)
{
    if (this->first_move_made == false)
    {
        std::random_device rand;
        std::default_random_engine reng(rand());
        /*
            At first I place a random stone on the field
        */
        std::uniform_int_distribution<int> r_distr(0, p_PH->get_rows());
        std::uniform_int_distribution<int> c_distr(0, p_PH->get_columns());
    
        if (p_PH->player_move(r_distr(reng), c_distr(reng), this->m_stone) == false)
        {
            this->first_move_made = false;
            return false;
        }
        else
        {
            this->x_pos = r_distr(reng);
            this->y_pos = c_distr(reng);
            this->first_move_made = true;
            return true;
        }
    }
    else
    {
        if(check_horizontal_move(p_PH) == false)
        {
            return false;
        }
    }
    return false;
}

int Smart_Bot::get_stone()
{
    return this->m_stone;
}