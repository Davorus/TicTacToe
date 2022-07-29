#include "Human_Player.hpp"
#include "../Utilities.hpp"

Human_Player::Human_Player(int stone)
    :m_stone{stone}
{    
}

void Human_Player::set_playfield(Playfield_Handler* p_PH)
{
    this->m_PH = p_PH;
}

void Human_Player::print_playfield()
{
    MyUtils::print("SPIELERFELD:");
    this->m_PH->print_Playfield();
}

void Human_Player::player_move()
{
    MyUtils::print("Enter y level");
    int y_axis;
    MyUtils::input(y_axis);
    MyUtils::print("Enter x level");
    int x_axis;
    MyUtils::input(x_axis);

    this->m_PH->player_move(y_axis, x_axis, m_stone);
}