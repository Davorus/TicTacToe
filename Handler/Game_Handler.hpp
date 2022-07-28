//----------------------------------------------------------------
#ifndef _GAME_HANDLER_HPP_INCLUDED
#define _GAME_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "EnumClasses.hpp"
#include "Playfield_Handler.hpp"
#include "Player.hpp"
//----------------------------------------------------------------

class Game_Handler
{
    private:
        int m_player_amount;
    public:
        Game_Handler();
        void set_player_amount(int p_player_amount);
        void start() const;
};

#endif