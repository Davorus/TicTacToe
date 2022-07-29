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
    this->m_PH = new Playfield_Handler();
}

Player_Type Gamesetup_Handler::get_Player_Type() const
{
    MyUtils::clear_screen();
    MyUtils::print("Choose what the next player should be:");
    MyUtils::print("   1. Human Player");
    MyUtils::print("   2. Random Bot");
    MyUtils::print("   3. Smart Bot");
    int input;
    do
    {
        MyUtils::print("Enter type for Player");
        MyUtils::input(input);
        
        if(input < 1 || input > 3)
            MyUtils::print("Enter valid input");
        else
        {
            if(input == 1)
                return Player_Type::Human;
            else if(input == 2)
                return Player_Type::RandomBot;
            else if(input == 3)
                return Player_Type::SmartBot;
        }
    } while (input < 1 || input > 3);
    return Player_Type::Error;
}

int Gamesetup_Handler::get_Menu_input() const
{
    int input = -1;
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

void Gamesetup_Handler::initialize_players()
{
    int amount_of_players = -1;
    do
    {
        MyUtils::print("Enter amount of players(max 3):");
        MyUtils::input(amount_of_players);
    } while (amount_of_players <= 1 || amount_of_players > 3);

    switch (amount_of_players)
    {
    case 2:
        {
            for(int i = 0; i < 2; i++)
                this->m_GH.get_players(this->get_Player_Type());
        }
        break;
    case 3:
        {
            for(int i = 0; i < 3; i++)
                this->m_GH.get_players(this->get_Player_Type());
        }
        break;
    default:
        return;
    }
}

void Gamesetup_Handler::play()
{
    MyUtils::print("Enter rows levels for playfield");
    int rows;
    MyUtils::input(rows);
    MyUtils::print("Enter columns levels for playfield");
    int columns;
    MyUtils::input(columns);
    
    this->m_PH->initialize_Playfield(rows, columns);
    
    this->initialize_players();
   
    this->m_GH.start(this->m_PH);
    
    MyUtils::print("Enter any key to return back to the main menu...");
    MyUtils::wait_for_enter();

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
