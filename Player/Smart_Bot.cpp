//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Smart_Bot.hpp"
//----------------------------------------------------------------

/*
    His instance number in creation is his marking on the playfield
*/
Smart_Bot::Smart_Bot(int stone)
    :m_stone{stone}
{
}

Player_Type Smart_Bot::get_player_type()
{
    return Player_Type::SmartBot;
}

bool Smart_Bot::player_move(Playfield_Handler* p_PH)
{
    return true;
}