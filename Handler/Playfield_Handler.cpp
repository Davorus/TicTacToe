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
    /*
        Saving the players entered playfield size, for better handling
        of the playfield
    */
    this->m_rows = rows;
    this->m_columns = columns;

    //Instanciation of a temporary 2D vector as playfield
    std::vector<std::vector<int>> tempVector(rows, std::vector<int>(columns)); 

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            tempVector.at(i).at(j) = 0;
        }
    }
    //Safe the created temporary vector in a member attribute
    this->m_playfield.assign(tempVector.begin(), tempVector.end());
}

void Playfield_Handler::print_Playfield() const
{
    MyUtils::clear_screen();
    for (int i = 0; i < this->m_rows; i++)
    {
        for (int j = 0; j < this->m_columns; j++)
        {
            std::cout << this->m_playfield.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}

bool Playfield_Handler::check_for_legal_play(int y_axis, int x_axis) const
{
    //-1 for rows in columns, indexes in arrays start counting by 0
    if (y_axis < 0 || y_axis > this->m_rows-1)
    {
        return false;
    }
    else if (x_axis < 0 || x_axis > this->m_columns-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Playfield_Handler::check_playfield_full()
{
    //Count the zeros in playfield, if there are none, playfield is full
    int count_zero = 0;
    for (int i = 0; i < this->m_rows; i++)
    {
        for (int j = 0; j < this->m_columns; j++)
        {
            if (this->m_playfield.at(i).at(j) == 0)
                count_zero++;
        }
    }

    if(count_zero == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Playfield_Handler::get_rows()
{
    return this->m_rows;
}

int Playfield_Handler::get_columns()
{
    return this->m_columns;
}

bool Playfield_Handler::check_horizontal_winner(int stone)
{
    int check_stone = 0;
    for (int i = 0; i < this->m_rows; i++)
    {
        for (int j = 0; j < this->m_columns; j++)
        {
            if (this->m_playfield.at(i).at(j) == stone)
            {
                check_stone++;
                if (check_stone == 3)
                {
                    return true;
                }
            }
            else
            {
                check_stone = 0;
            }
        }
        check_stone = 0;
    }
    return false;
}

bool Playfield_Handler::check_vertical_winner(int stone)
{
    int check_stone = 0;
    for (int i = 0; i < this->m_columns; i++)
    {
        check_stone = 0;
        for (int j = 0; j < this->m_rows; j++)
        {
            if (this->m_playfield.at(j).at(i) == stone)
            {
                check_stone++;
                if (check_stone == 3)
                {
                    return true;
                }
            }
            else
            {
                check_stone = 0;
            }
        }
    }
    return false;
}

bool Playfield_Handler::check_winner_diagonal_left_right(int stone)
{
    for (int i = 0; i < this->m_rows; i++)
    {
        for (int j = 0; j < this->m_columns; j++)
        {
            if (i < this->m_rows-2 && j < this->m_columns-2)
            {
                if (this->m_playfield.at(i).at(j) == stone)
                    if (this->m_playfield.at(i+1).at(j+1) == stone)
                        if (this->m_playfield.at(i+2).at(j+2) == stone)
                            return true;
            }
        }
    }
    return false;
}

bool Playfield_Handler::check_winner_diagonal_right_left(int stone)
{
    for (int i = 0; i < this->m_rows; i++)
    {
        for (int j = this->m_rows-1; j > 0; j--)
        {
            if (j >= 2 && i < this->m_rows-2)
            {
                if (this->m_playfield.at(i).at(j) == stone)
                    if (this->m_playfield.at(i+1).at(j-1) == stone)
                        if (this->m_playfield.at(i+2).at(j-2) == stone)
                            return true;
            }
        }
    }
    return false;
}

bool Playfield_Handler::check_diagonal_winner(int stone)
{
    if(check_winner_diagonal_left_right(stone) == true)
    {
        return true;
    }

    if(check_winner_diagonal_right_left(stone) == true)
    {
        return true;
    }       

    return false;
}

bool Playfield_Handler::check_winner(int stone)
{
    
    if (this->check_horizontal_winner(stone) == true)
    {
        std::cout << "Player " << stone << " has won horizontally!" << std::endl;
        return true;
    }
    
    if (this->check_vertical_winner(stone) == true)
    {
        std::cout << "Player " << stone << " has won vertically!" << std::endl;
        return true;
    }
    
    if (this->check_diagonal_winner(stone) == true)
    {
        std::cout << "Player " << stone << " has won diagonally!" << std::endl;
        return true;
    }
    
    return false;
}

bool Playfield_Handler::player_move(int y_axis, int x_axis, int player_stone)
{
    bool legal = false;
    legal = this->check_for_legal_play(y_axis, x_axis);
    if (legal == false)
    {
        return false;
    }
    else if (legal == true)
    {
        if (this->m_playfield.at(y_axis).at(x_axis) != 0) //already used field can't be used 2. time
        {
            return false;
        }
        else
        {
            this->m_playfield.at(y_axis).at(x_axis) = player_stone; //sets mark of player if field is truely 0
            return true;
        }
    }
    return false;
}