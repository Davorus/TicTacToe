#ifndef _PLAYER_HPP_INCLUDED
#define _PLAYER_HPP_INCLUDED

class Player
{
    public:                         //Should save what number the player will place on the field 
        virtual void player_move();
        virtual void get_player_type();
};

#endif