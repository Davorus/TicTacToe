//----------------------------------------------------------------
#ifndef _GAMESETUP_HANDLER_HPP_INCLUDED
#define _GAMESETUP_HANDLER_HPP_INCLUDED
//----------------------------------------------------------------
//----------------------------------------------------------------
#include "Game_Handler.hpp"
#include "EnumClasses.hpp"
//----------------------------------------------------------------

class Gamesetup_Handler
{
    private:
        const Game_Handler m_GH;
        int get_Menu_input() const;
        void set_up_mode(Menu_Options mode) const;
        void credits() const;
        void gamerules() const;
        void play() const;
        int initialize_players() const;
    public:
        Gamesetup_Handler();
        Bot_Type get_Bot1_Type() const;
        Bot_Type get_Bot2_Type() const;
        void print_Start_Menu() const;
};

#endif