//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Human_Player.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

Human_Player::Human_Player(int stone)
    :m_stone{stone}
{
}

int Human_Player::get_player_type()
{
    return static_cast<int>(Player_Type::Human);
}

void Human_Player::player_move(Playfield_Handler* p_PH)
{
    MyUtils::print("Enter y level");
    int y_axis;
    MyUtils::input(y_axis);
    MyUtils::print("Enter x level");
    int x_axis;
    MyUtils::input(x_axis);

    p_PH->player_move(y_axis, x_axis, m_stone);
}