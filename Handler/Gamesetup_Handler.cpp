#include <iostream>
#include "Gamesetup_Handler.hpp"

enum class Menu_Options
{
    Credits = 0,
    Gamerules = 1,
    Play = 2,
    End_Program = 3
};

Gamesetup_Handler::Gamesetup_Handler()
    :bot1{Bot_Type::NotDeclared}
    ,bot2{Bot_Type::NotDeclared}
{
}

Bot_Type Gamesetup_Handler::get_Bot1_Type()
{
    return this->bot1;
}

Bot_Type Gamesetup_Handler::get_Bot2_Type()
{
    return this->bot2;
}

void Gamesetup_Handler::set_Bot_Type()
{

}

void Gamesetup_Handler::print_Start_Menu()
{
    std::cout << "***********MENU***********" << std::endl;
    std::cout << "0. Credits" << std::endl;
    std::cout << "1. Gamerules" << std::endl;
    std::cout << "2. Play" << std::endl;
    std::cout << "3. End Program" << std::endl;
}