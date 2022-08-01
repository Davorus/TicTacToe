//----------------------------------------------------------------
#ifndef _PLAYER_HPP_INCLUDED
#define _PLAYER_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "../EnumClasses.hpp"
//----------------------------------------------------------------

class Player
{
    public:                         //Should save what number the player will place on the field 
        Player_Type m_type;
        virtual void player_move();
        virtual int get_player_type()=0;
};

#endif