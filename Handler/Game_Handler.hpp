//----------------------------------------------------------------
#ifndef _GAME_HANDLER_HPP_INCLUDED
#define _GAME_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
#include <vector>
//----------------------------------------------------------------
#include "../EnumClasses.hpp"
#include "Playfield_Handler.hpp"
#include "../Player/Player.hpp"
#include "../Player/Human_Player.hpp"
#include "../Player/Random_Bot.hpp"
#include "../Player/Smart_Bot.hpp"
//----------------------------------------------------------------

class Game_Handler
{
    private:
        std::vector<Player*> m_player;
        std::vector<Player_Type> m_to_be_set_players;
        void initialize_players();
    public:
        Game_Handler();
        ~Game_Handler();
        void set_players(Player_Type type);
        void start(Playfield_Handler* p_PH);
};

#endif