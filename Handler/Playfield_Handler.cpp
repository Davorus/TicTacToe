//----------------------------------------------------------------
#include <iostream>
//----------------------------------------------------------------
#include "Playfield_Handler.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

Playfield_Handler::Playfield_Handler()
    :m_gameStarted{true}
    ,m_rows{0}
    ,m_columns{0}    
{}

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
    for(int i = 0; i < this->m_rows; i++)
    {
        for(int j = 0; j < this->m_columns; j++)
        {
            std::cout << this->m_playfield.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

void Playfield_Handler::check_for_legal_play() const
{

}