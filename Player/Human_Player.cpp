#include "Human_Player.hpp"
#include "../Utilities.hpp"

Human_Player::Human_Player(Playfield_Handler* p_PH, int stone)
    :m_PH{p_PH}
    ,m_stone{stone}
{    
}

void Human_Player::player_move()
{
        MyUtils::print("Enter y level: ");
        int y_axis;
        MyUtils::input(y_axis);
        MyUtils::print("Enter x level: ");
        int x_axis;
        MyUtils::input(x_axis);
        MyUtils::print("ENTERED X: ");
        MyUtils::print(x_axis);
        MyUtils::print("ENTERED Y: ");
        MyUtils::print(y_axis);

        m_PH->player_move(y_axis, x_axis, m_stone);
    
}