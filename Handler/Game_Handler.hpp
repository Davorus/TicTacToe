//----------------------------------------------------------------
#ifndef _GAME_HANDLER_HPP_INCLUDED
#define _GAME_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
#include <vector>
//----------------------------------------------------------------
#include "EnumClasses.hpp"
#include "Playfield_Handler.hpp"
#include "Player.hpp"
#include "EnumClasses.hpp"
//----------------------------------------------------------------

class Game_Handler
{
    private:
        std::vector<Player> player;
        std::vector<Player_Type> to_be_set_players;
    public:
        Game_Handler();
        void set_players(Player_Type type);
        void start() const;
};

#endif