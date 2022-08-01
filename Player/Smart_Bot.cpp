//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Smart_Bot.hpp"
//----------------------------------------------------------------

Smart_Bot::Smart_Bot(int stone)
    :m_stone{stone}
{
}

Player_Type Smart_Bot::get_player_type()
{
    return Player_Type::SmartBot;
}