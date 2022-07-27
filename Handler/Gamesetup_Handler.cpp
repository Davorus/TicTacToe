#include <iostream>
#include <unistd.h> //Warum meldet der hier einen Fehler der verschwindet wenn ich draufklicke?
#include "Gamesetup_Handler.hpp"

Gamesetup_Handler::Gamesetup_Handler(Game_Handler& p_GH)
    :m_bot1{Bot_Type::NotDeclared}
    ,m_bot2{Bot_Type::NotDeclared}
    ,m_GH{p_GH}
{
}

Bot_Type Gamesetup_Handler::get_Bot1_Type() const
{
    return this->m_bot1;
}

Bot_Type Gamesetup_Handler::get_Bot2_Type() const
{
    return this->m_bot2;
}

void Gamesetup_Handler::set_Bot_Type()
{

}

int Gamesetup_Handler::get_Menu_input() const
{
    int input = 0;
    do
    {
        std::cout << "Enter value: ";
        std::cin >> input;
    } while (input < 0 || input > 3);
    return input;
}

void Gamesetup_Handler::credits() const
{
    std::cout << "Credits are overrated" << std::endl;
    sleep(4);
    std::cout << "BUT!" << std::endl;
    sleep(1.5);
    std::cout << "This game belongs to David Movsesjan who made it" << std::endl;
    sleep(1.5);
    std::cout << "as a university project. This credits aren't to be" << std::endl;
    sleep(1.5);
    std::cout << "taken too serious." << std::endl;
    sleep(4);
    std::cout << "Or maybe they should?" << std::endl;
    sleep(2);

    this->print_Start_Menu();
}

void Gamesetup_Handler::gamerules() const
{
    std::cout << "Gamerules:" << std::endl;
    sleep(3);
    std::cout << "Try to place 3 of your moves in a" << std::endl;
    sleep(1);
    std::cout << "    1. horizontal" << std::endl;
    sleep(1);
    std::cout << "    2. vertical" << std::endl;
    sleep(1);
    std::cout << "    3. diagonal" << std::endl;
    sleep(1);
    std::cout << "way to win the game!" << std::endl;
    sleep(1);
    this->print_Start_Menu();
}

void Gamesetup_Handler::play() const
{
    m_GH.start();
    this->print_Start_Menu();
}

void Gamesetup_Handler::set_up_mode(Menu_Options mode) const
{
    switch(mode)
    {
        case Menu_Options::Credits: this->credits(); break;
        case Menu_Options::Gamerules: this->gamerules(); break;
        case Menu_Options::Play: this->play(); break;
        case Menu_Options::End_Program: return;
    }
}

void Gamesetup_Handler::print_Start_Menu() const
{
    std::cout << "***********MENU***********" << std::endl;
    std::cout << "0. Credits" << std::endl;
    std::cout << "1. Gamerules" << std::endl;
    std::cout << "2. Play" << std::endl;
    std::cout << "3. End Program" << std::endl;
    int user_input;
    user_input = this->get_Menu_input();
    set_up_mode((Menu_Options)user_input);
}
