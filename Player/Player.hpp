//----------------------------------------------------------------
#ifndef _PLAYER_HPP_INCLUDED
#define _PLAYER_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "../EnumClasses.hpp"
#include "../Handler/Playfield_Handler.hpp"
//----------------------------------------------------------------

class Player
{
    public:                
        /*
            No direct instances needed, just call this method for any derived
            class of Player, to let him make a move
        */
        int m_stone;
        virtual int get_stone();
        virtual bool player_move(Playfield_Handler* p_PH); 
        virtual Player_Type get_player_type()=0;
};

#endif