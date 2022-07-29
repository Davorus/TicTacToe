#ifndef _HUMAN_PLAYER_HPP_INCLUDED
#define _HUMAN_PLAYER_HPP_INCLUDED

#include "Player.hpp"
#include "../Handler/Playfield_Handler.hpp"

class Human_Player : public Player
{
    private:
        int m_stone;
        Playfield_Handler* m_PH;
    public:
        Human_Player(int stone);
        void set_playfield(Playfield_Handler* p_PH);
        void player_move();
        void print_playfield();
};

#endif