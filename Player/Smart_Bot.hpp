//----------------------------------------------------------------
#ifndef _SMART_BOT_HPP_INCLUDED
#define _SMART_BOT_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Player.hpp"
//----------------------------------------------------------------

class Smart_Bot : public Player
{
    private:
        int m_stone;
    public:
        Smart_Bot(int stone);
        bool player_move(Playfield_Handler* p_PH);
        Player_Type get_player_type();
        int get_stone();
};

#endif