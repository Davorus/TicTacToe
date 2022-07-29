//----------------------------------------------------------------
#include <iostream>
#include <random>
//----------------------------------------------------------------
#include "Playfield_Handler.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

Playfield_Handler::Playfield_Handler()
    :m_gameStarted{true}
    ,m_rows{0}
    ,m_columns{0}    
{
}

void Playfield_Handler::initialize_Playfield(int rows, int columns)
{
    this->m_rows = rows;
    this->m_columns = columns;
    std::vector<std::vector<int>> tempVector(rows, std::vector<int>(columns));

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            tempVector.at(i).at(j) = 0;
        }
    }
    this->m_playfield.assign(tempVector.begin(), tempVector.end());
}

void Playfield_Handler::print_Playfield() const
{
    //MyUtils::clear_screen();
    for(int i = 0; i < this->m_rows; i++)
    {
        for(int j = 0; j < this->m_columns; j++)
        {
            std::cout << this->m_playfield.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

bool Playfield_Handler::check_for_legal_play(int y_axis, int x_axis) const
{
    if(y_axis < 0 || y_axis > this->m_rows)
    {
        return false;
    }
    else if(x_axis < 0 || x_axis > this->m_columns)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Playfield_Handler::player_move(int y_axis, int x_axis, int player_move)
{
    bool legal = false;
    legal = this->check_for_legal_play(y_axis, x_axis);
    if(legal == false)
    {
        return false;
    }
    else if(legal == true)
    {
        if(this->m_playfield.at(y_axis).at(x_axis) != 0)
        {
            return false;
        }
        else
        {
            this->m_playfield.at(y_axis).at(x_axis) = player_move;
            return true;
        }
    }
    return false;
}