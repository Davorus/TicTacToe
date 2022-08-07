//----------------------------------------------------------------
#include <random>
#include <iostream>
//----------------------------------------------------------------
#include "Smart_Bot.hpp"
#include "Random_Bot.hpp"
//----------------------------------------------------------------

/*
    His instance number in creation is his marking on the playfield
*/
Smart_Bot::Smart_Bot(int stone)
    :m_stone{stone}
    ,m_placed_stones{0}
{
}

Player_Type Smart_Bot::get_player_type()
{
    return Player_Type::SmartBot;
}

void Smart_Bot::count_placed_stones(Playfield_Handler* p_PH)
{
    for (int i = 0; i < p_PH->get_rows(); i++)
    {
        for (int j = 0; j < p_PH->get_columns(); j++)
        {
            if (p_PH->m_playfield.at(i).at(j) == this->m_stone)
                this->m_stone++;
        }
    }
}

bool Smart_Bot::check_next_move(Playfield_Handler* p_PH)
{

}

bool Smart_Bot::make_random_move(Playfield_Handler* p_PH)
{
    Random_Bot* r = new Random_Bot(this->m_stone);
    return r->player_move(p_PH);
}

bool Smart_Bot::horizontal_move(Playfield_Handler* p_PH)
{
    for (int i = 0; i < p_PH->get_rows()+1; i++)
    {
        for (int j = 0; j < p_PH->get_columns()+1; j++)
        {
            if (p_PH->m_playfield.at(i).at(j) == this->m_stone)
            {
                if (j < p_PH->get_columns())
                {
                    if (p_PH->m_playfield.at(i).at(j+1) == this->m_stone)
                    {
                        if (p_PH->m_playfield.at(i).at(j+2) == 0)
                        {
                            p_PH->player_move(i, j+2, this->m_stone);
                            return true;
                        }
                        p_PH->player_move(i, j-1, this->m_stone);
                        return true;
                    }
                    p_PH->player_move(i, j+1, this->m_stone);
                    return true;
                }
                else if (j == p_PH->get_columns())
                 {
                    if (p_PH->m_playfield.at(i).at(j-1) == this->m_stone)
                    {
                        if (p_PH->m_playfield.at(i).at(j-2) == 0)
                        {
                            p_PH->player_move(i, j-2, this->m_stone);
                            return true;
                        }
                        p_PH->player_move(i, j+1, this->m_stone);
                        return true;
                    }
                    p_PH->player_move(i, j-1, this->m_stone);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Smart_Bot::vertical_move(Playfield_Handler* p_PH)
{
    for (int i = 0; i < p_PH->get_columns()+1; i++)
    {
        for (int j = 0; j < p_PH->get_rows()+1; j++)
        {
            if (p_PH->m_playfield.at(i).at(j) == this->m_stone)
            {
                if (i < p_PH->get_rows())
                {
                    if (p_PH->m_playfield.at(i+1).at(j) == this->m_stone)
                    {
                        p_PH->player_move(i-1, j, this->m_stone);
                        return true;
                    }
                    p_PH->player_move(i+1, j, this->m_stone);
                    return true;
                }
                else if (i == p_PH->get_rows())
                 {
                    if (p_PH->m_playfield.at(i-1).at(j) == this->m_stone)
                    {
                        p_PH->player_move(i+1, j, this->m_stone);
                        return true;
                    }
                    p_PH->player_move(i-1, j, this->m_stone);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Smart_Bot::player_move(Playfield_Handler* p_PH)
{
    if(this->m_placed_stones == 0)
    {
        this->m_placed_stones++;
        return this->make_random_move(p_PH);
    }
    else
    {
        if (this->horizontal_move(p_PH) == true)
        {
            return true;
        }
        if (this->vertical_move(p_PH) == true)
        {
            return true;
        }
    }
    return false;
}

int Smart_Bot::get_stone()
{
    return this->m_stone;
}