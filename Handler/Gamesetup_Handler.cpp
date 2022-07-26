//----------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
//----------------------------------------------------------------
#include "Gamesetup_Handler.hpp"
#include "../Utilities.hpp"
//----------------------------------------------------------------

Gamesetup_Handler::Gamesetup_Handler()
{
    //Pointer for overall simpler handling
    this->m_PH = new Playfield_Handler(); 
}

Gamesetup_Handler::~Gamesetup_Handler()
{
    delete this->m_PH;
}

//Player can choose what players he wants to play against
Player_Type Gamesetup_Handler::set_player_type() const
{
    MyUtils::clear_screen();
    MyUtils::print("Choose what the next player should be:");
    MyUtils::print("\t1. Human Player");
    MyUtils::print("\t2. Random Bot");
    MyUtils::print("\t3. Smart Bot");
    
    int input = 0;
    do
    {
        MyUtils::print("Enter type for Player");
        MyUtils::input(input);
        
        if (input < 1 || input > 3)
            MyUtils::print("Enter valid input");
        else
        {
            if (input == 1)
                return Player_Type::Human;
            else if (input == 2)
                return Player_Type::RandomBot;
            else if (input == 3)
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

//Some credits, because why not
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

    this->print_start_menu();
}

//For those who live behind the moon
void Gamesetup_Handler::gamerules()
{
    MyUtils::clear_screen();
    MyUtils::print("Gamerules:");
    sleep(3);
    MyUtils::print("Try to place 3 of your moves in a");
    sleep(1);
    MyUtils::print("\t1. horizontal");
    sleep(1);
    MyUtils::print("\t2. vertical");
    sleep(1);
    MyUtils::print("\t3. diagonal");
    sleep(1);
    MyUtils::print("way to win the game!");
    MyUtils::print("Press any key to return to the main menu...");
    MyUtils::wait_for_enter();
    this->print_start_menu();
}

void Gamesetup_Handler::initialize_players()
{
    MyUtils::clear_screen();
    int amount_of_players = 0;
    MyUtils::print("Enter amount of players:");
    MyUtils::input(amount_of_players);

    for (int i = 0; i < amount_of_players; i++)
    {
        this->m_GH.set_players(this->set_player_type());
    }
}

void Gamesetup_Handler::play()
{
    /* Solution inspired by this thread:
        https://stackoverflow.com/questions/12463750/c-searching
        -text-file-for-a-particular-string-and-returning-the-line-number-wh
    */
    int rows = 0;
    std::string line;
    std::ifstream file_input;
    file_input.open("config.txt");
    std::string s_height = "Height: ";
    while (getline(file_input, line))
    { 
        auto pointer_to_int = line.find(s_height, 0);
        if (pointer_to_int != std::string::npos) 
        {
            pointer_to_int += 8;
            std::string temp = line.substr(pointer_to_int, 1);
            rows = std::stoi(temp);
            if (rows < 3)
                rows = 3;
        }
    }
    file_input.close();

    int columns = 0;
    file_input.open("config.txt");
    std::string s_width = "Width: ";
    while (getline(file_input, line))
    { 
        auto pointer_to_int = line.find(s_width, 0);
        if (pointer_to_int != std::string::npos) 
        {
            pointer_to_int += 7;
            std::string temp = line.substr(pointer_to_int, 1);
            columns = std::stoi(temp);
            if (columns < 3)
                columns = 3;
        }
    }
    file_input.close();
    
    this->m_PH->initialize_playfield(rows, columns);
    
    this->initialize_players();
   
    this->m_GH.start(this->m_PH);
    
    MyUtils::print("Enter any key to return back to the main menu...");
    MyUtils::wait_for_enter();

    return;
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

void Gamesetup_Handler::print_start_menu()
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
