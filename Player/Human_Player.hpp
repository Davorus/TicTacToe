//----------------------------------------------------------------
#ifndef _HUMAN_PLAYER_HPP_INCLUDED
#define _HUMAN_PLAYER_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Player.hpp"
#include "../Handler/Playfield_Handler.hpp"
//----------------------------------------------------------------

class Human_Player : public Player
{
    private:
        int m_stone;
    public:
        Human_Player(int stone);
        Player_Type get_player_type();
        void print_playfield(Playfield_Handler* p_PH);
        void player_move(Playfield_Handler* p_PH);
};

#endif