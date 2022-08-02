//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Human_Player.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

/*
    His instance number in creation is his marking on the playfield
*/
Human_Player::Human_Player(int stone) 
    :m_stone{stone}
{
}

Player_Type Human_Player::get_player_type()
{
    return Player_Type::Human;
}

bool Human_Player::player_move(Playfield_Handler* p_PH)
{
    MyUtils::print("Enter y level");
    int y_axis;
    MyUtils::input(y_axis);
    MyUtils::print("Enter x level");
    int x_axis;
    MyUtils::input(x_axis);

    return p_PH->player_move(y_axis, x_axis, m_stone);
}

int Human_Player::get_stone()
{
    return this->m_stone;
}