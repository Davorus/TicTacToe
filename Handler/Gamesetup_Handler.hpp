#ifndef _GAMESETUP_HANDLER_HPP_INCLUDED
#define _GAMESETUP_HANDLER_HPP_INCLUDED

enum class Bot_Type
{
    NotDeclared = 0,
    RandomBot = 1,
    SmartBot = 2,
    Error = 3
};

class Gamesetup_Handler
{
    private:
        const Bot_Type bot1, bot2;
    public:
        Gamesetup_Handler();
        Bot_Type get_Bot1_Type();
        Bot_Type get_Bot2_Type();
        void set_Bot_Type();
        void print_Start_Menu();
        void get_Menu_input();
};

#endif