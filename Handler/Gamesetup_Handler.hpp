#ifndef _GAMESETUP_HANDLER_HPP_INCLUDED
#define _GAMESETUP_HANDLER_HPP_INCLUDED

enum class Bot_Type
{
    NotDeclared = 0,
    RandomBot = 1,
    SmartBot = 2,
    Error = 3
};

enum class Menu_Options
{
    Credits = 0,
    Gamerules = 1,
    Play = 2,
    End_Program = 3
};
class Gamesetup_Handler
{
    private:
        const Bot_Type m_bot1, m_bot2;
    public:
        Gamesetup_Handler();
        Bot_Type get_Bot1_Type();
        Bot_Type get_Bot2_Type();
        void set_Bot_Type();
        void print_Start_Menu();
        int get_Menu_input();
        void set_up_mode(Menu_Options mode);
        void credits();
        void gamerules();
        void play();
};

#endif