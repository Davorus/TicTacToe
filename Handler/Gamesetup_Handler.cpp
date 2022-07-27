//----------------------------------------------------------------
#include <iostream>
#include <unistd.h> 
//----------------------------------------------------------------
#include "Gamesetup_Handler.hpp"
//----------------------------------------------------------------

Gamesetup_Handler::Gamesetup_Handler()
{
}

Gamesetup_Handler::Gamesetup_Handler(Game_Handler& p_GH)
    :m_GH{p_GH}
{
}

Bot_Type Gamesetup_Handler::get_Bot1_Type() const
{
    std::cout << "Choose what bot1 should be:" << std::endl;
    std::cout << "   1. Random Bot" << std::endl;
    std::cout << "   2. Smart Bot" << std::endl;
    int input;
    do
    {
        std::cout << "Enter type for Bot1" << std::endl;
        std::cin >> input;
        
        if(input != 1 || input != 2)
            std::cout << "Enter valid input" << std::endl;
        else
        {
            if(input == 1)
                return Bot_Type::RandomBot;
            else if(input == 2)
                return Bot_Type::SmartBot;
        }
    } while (input < 1 || input > 2);
    return Bot_Type::Error;
}

Bot_Type Gamesetup_Handler::get_Bot2_Type() const
{
    std::cout << "Choose what bot2 should be:" << std::endl;
    std::cout << "   1. Random Bot" << std::endl;
    std::cout << "   2. Smart Bot" << std::endl;
    int input;
    do
    {
        std::cout << "Enter type for Bot1" << std::endl;
        std::cin >> input;
        
        if(input != 1 || input != 2)
        {
            std::cout << "Enter valid input" << std::endl;
        }
        else
        {
            if(input == 1)
                return Bot_Type::RandomBot;
            else if(input == 2)
                return Bot_Type::SmartBot;
        }
    } while (input < 1 || input > 2);
    return Bot_Type::Error;
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

int Gamesetup_Handler::initialize_players() const
{
    int amount_of_players = -1;
    do
    {
        std::cout << "Enter amount of players(max 3):";       
        std::cin >> amount_of_players;
    } while (amount_of_players <= 1 || amount_of_players > 3);
    return amount_of_players;
}

void Gamesetup_Handler::play() const
{
    int player_amount = this->initialize_players();
    
    if(player_amount == 2)
    {
        Bot_Type bot1 = this->get_Bot1_Type();
        m_GH.start(player_amount, bot1);
    }
    else
    {
        Bot_Type bot1 = this->get_Bot1_Type();
        Bot_Type bot2 = this->get_Bot2_Type();
        m_GH.start(player_amount, bot1, bot2);
    }
    
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
