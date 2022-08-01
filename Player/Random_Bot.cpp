//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Random_Bot.hpp"
//----------------------------------------------------------------

Random_Bot::Random_Bot(int stone)
    :m_stone{stone}
{
}

Player_Type Random_Bot::get_player_type()
{
    return Player_Type::RandomBot;
}