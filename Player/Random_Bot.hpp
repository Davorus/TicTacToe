//----------------------------------------------------------------
#ifndef _RANDOM_BOT_HPP_INCLUDED
#define _RANDOM_BOT_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Player.hpp"
//----------------------------------------------------------------

class Random_Bot : public Player
{
    public:
        Player_Type get_player_type();
};

#endif