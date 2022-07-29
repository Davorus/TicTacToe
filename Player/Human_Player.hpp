#ifndef _HUMAN_PLAYER_HPP_INCLUDED
#define _HUMAN_PLAYER_HPP_INCLUDED

#include "Player.hpp"
#include "../Handler/Playfield_Handler.hpp"

class Human_Player : public Player
{
    private:
        int m_stone;
    public:
        Playfield_Handler* m_PH;
        Human_Player(Playfield_Handler* p_PH, int stone);
        void player_move();
};

#endif