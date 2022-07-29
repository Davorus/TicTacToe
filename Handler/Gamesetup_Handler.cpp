//----------------------------------------------------------------
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
//----------------------------------------------------------------
#include "Gamesetup_Handler.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

Gamesetup_Handler::Gamesetup_Handler()
{
}

Bot_Type Gamesetup_Handler::get_Bot1_Type() const
{
    MyUtils::clear_screen();
    MyUtils::print("Choose what bot1 should be:");
    MyUtils::print("   1. Random Bot");
    MyUtils::print("   2. Smart Bot");
    int input;
    do
    {
        MyUtils::print("Enter type for Bot1");
        MyUtils::input(input);
        
        if(input < 1 || input > 2)
            MyUtils::print("Enter valid input");
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
    MyUtils::wait_for_enter();
    MyUtils::print("Choose what bot2 should be:");
    MyUtils::print("   1. Random Bot");
    MyUtils::print("   2. Smart Bot");
    int input;
    do
    {
        MyUtils::print("Enter type for Bot2");
        MyUtils::input(input);
        
        if(input < 1 || input > 2)
        {
            MyUtils::print("Enter valid input");
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
        MyUtils::input(input);
    } while (input < 0 || input > 3);
    return input;
}

void Gamesetup_Handler::credits()
{
    MyUtils::clear_screen();
    MyUtils::print("Credits are overrated");
    sleep(4);
    MyUtils::print("BUT!");
    sleep(1.5);
    MyUtils::print("This game belongs to David Movsesjan who made it");
    sleep(1.5);
    MyUtils::print("as a university project. This credits aren't to be");
    sleep(1.5);
    MyUtils::print("taken too serious.");
    sleep(4);
    MyUtils::print("Or maybe they should?");
    MyUtils::print("Press any key to return to the main menu...");
    MyUtils::wait_for_enter();

    this->print_Start_Menu();
}

void Gamesetup_Handler::gamerules()
{
    MyUtils::clear_screen();
    MyUtils::print("Gamerules:");
    sleep(3);
    MyUtils::print("Try to place 3 of your moves in a");
    sleep(1);
    MyUtils::print("    1. horizontal");
    sleep(1);
    MyUtils::print("    2. vertical");
    sleep(1);
    MyUtils::print("    3. diagonal");
    sleep(1);
    MyUtils::print("way to win the game!");
    MyUtils::print("Press any key to return to the main menu...");
    MyUtils::wait_for_enter();
    this->print_Start_Menu();
}

int Gamesetup_Handler::initialize_players()
{
    int amount_of_players = -1;
    do
    {
        MyUtils::print("Enter amount of players(max 3):");
        MyUtils::input(amount_of_players);
    } while (amount_of_players <= 1 || amount_of_players > 3);
    return amount_of_players;
}

void Gamesetup_Handler::play()
{
    int player_amount = this->initialize_players();
   
    this->m_GH.set_player_amount(player_amount);
    this->m_GH.start();
    
    this->print_Start_Menu();
}

void Gamesetup_Handler::set_up_mode(Menu_Options mode)
{
    switch(mode)
    {
        case Menu_Options::Credits: this->credits(); break;
        case Menu_Options::Gamerules: this->gamerules(); break;
        case Menu_Options::Play: this->play(); break;
        case Menu_Options::End_Program: return;
        default: break;
    }
}

void Gamesetup_Handler::print_Start_Menu()
{
    MyUtils::clear_screen();
    MyUtils::print("***********MENU***********");
    MyUtils::print("0. Credits");
    MyUtils::print("1. Gamerules");
    MyUtils::print("2. Play");
    MyUtils::print("3. End Program");
    int user_input;
    user_input = this->get_Menu_input();
    set_up_mode((Menu_Options)user_input);
}
