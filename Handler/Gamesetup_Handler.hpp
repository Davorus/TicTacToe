//----------------------------------------------------------------
#ifndef _GAMESETUP_HANDLER_HPP_INCLUDED
#define _GAMESETUP_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
#include <vector>
//----------------------------------------------------------------
#include "Game_Handler.hpp"
#include "../EnumClasses.hpp"
#include "Playfield_Handler.hpp"
#include "../Player/Human_Player.hpp"
#include "../Player/Random_Bot.hpp"
#include "../Player/Smart_Bot.hpp"
//----------------------------------------------------------------

class Gamesetup_Handler
{
    private:
        Game_Handler m_GH;
        Playfield_Handler* m_PH;
        int get_Menu_input() const;
        void set_up_mode(Menu_Options mode);
        void credits();
        void gamerules();
        void play();
        void initialize_players();
        bool check_horizontal_winner(int stone);
    public:
        Gamesetup_Handler();
        Player_Type set_Player_Type() const;
        void print_Start_Menu();
        bool check_winner(int stone);
};

#endif