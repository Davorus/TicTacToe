//----------------------------------------------------------------
//----------------------------------------------------------------
#include "PreSmartBot.hpp"
//----------------------------------------------------------------

PreSmartBot::PreSmartBot(int stone)
    :m_stone{stone}
{
}

bool PreSmartBot::player_move()
{
    return true;
}

int PreSmartBot::get_stone()
{
    return this->m_stone;
}