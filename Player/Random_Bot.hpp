//----------------------------------------------------------------
#ifndef _RANDOM_BOT_HPP_INCLUDED
#define _RANDOM_BOT_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Player.hpp"
//----------------------------------------------------------------

class Random_Bot : public Player
{
    private:
        int m_stone;
    public:
        Random_Bot(int stone);
        Player_Type get_player_type();
        void player_move(Playfield_Handler* p_PH);
};

#endif