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
        const Bot_Type m_bot1, m_bot2;
        const Game_Handler m_GH;
        int get_Menu_input() const;
        void set_up_mode(Menu_Options mode) const;
        void credits() const;
        void gamerules() const;
        void play() const;
        void set_Bot_Type();
    public:
        Gamesetup_Handler();
        Gamesetup_Handler(Game_Handler& p_GH);
        Bot_Type get_Bot1_Type() const;
        Bot_Type get_Bot2_Type() const;
        void print_Start_Menu() const;
};

#endif