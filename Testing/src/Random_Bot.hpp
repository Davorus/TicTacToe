//----------------------------------------------------------------
#ifndef _RANDOM_BOT_HPP_INCLUDED
#define _RANDOM_BOT_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Playfield_Handler.hpp"
//----------------------------------------------------------------

class Random_Bot
{
    private:
        int m_stone;
    public:
        Random_Bot(int stone);
        bool player_move(Playfield_Handler* p_PH);
        int get_stone();
};

#endif