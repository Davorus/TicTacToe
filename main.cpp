#include <iostream>

#include "Game_Handler.hpp"
#include "Gamesetup_Handler.hpp"

int main()
{
    Gamesetup_Handler h;
    std::cout << (int)h.get_Bot1_Type();
}
