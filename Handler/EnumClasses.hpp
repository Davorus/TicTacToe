#ifndef _ENUMCLASSES_HPP_INCLUDED
#define _ENUMCLASSES_HPP_INCLUDED

enum class Player_Type
{
    NotDeclared = 0,
    Human = 1,
    RandomBot = 2,
    SmartBot = 3,
    Error = 4
};

enum class Menu_Options
{
    Credits = 0,
    Gamerules = 1,
    Play = 2,
    End_Program = 3
};

#endif