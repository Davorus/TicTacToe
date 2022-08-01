//----------------------------------------------------------------
#ifndef _GAME_HANDLER_HPP_INCLUDED
#define _GAME_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
#include <vector>
//----------------------------------------------------------------
#include "../EnumClasses.hpp"
#include "Playfield_Handler.hpp"
#include "Player.hpp"
#include "Human_Player.hpp"
#include "Random_Bot.hpp"
#include "Smart_Bot.hpp"
//----------------------------------------------------------------

class Game_Handler
{
    private:
        std::vector<Player*> m_player;
        std::vector<Player_Type> m_to_be_set_players;
        void initialize_players();
    public:
        Game_Handler();
        void set_players(Player_Type type);
        void start(Playfield_Handler* p_PH);
};

#endif