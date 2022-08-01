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
    public:                         //Should save what number the player will place on the field 
        Player_Type m_type;
        virtual void player_move(Playfield_Handler* p_PH);
        virtual Player_Type get_player_type()=0;
};

#endif