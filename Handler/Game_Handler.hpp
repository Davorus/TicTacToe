//----------------------------------------------------------------
#ifndef _GAME_HANDLER_HPP_INCLUDED
#define _GAME_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "EnumClasses.hpp"
//----------------------------------------------------------------

class Game_Handler
{
    public:
        Game_Handler();
        void start(int p_Player_Amount, Bot_Type bot1) const;
        void start(int p_Player_Amount, Bot_Type bot1, Bot_Type bot2) const;
};

#endif