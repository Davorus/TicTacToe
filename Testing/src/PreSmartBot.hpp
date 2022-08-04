//----------------------------------------------------------------
#ifndef _PRESMARTBOT_HPP_INCLUDED
#define _PRESMARTBOT_HPP_INCLUDED
//----------------------------------------------------------------
#include <iostream>
//----------------------------------------------------------------
//----------------------------------------------------------------

class PreSmartBot
{
    private:
        int m_stone;
    public:
        PreSmartBot(int stone);
        bool player_move();
        int get_stone();
};

#endif