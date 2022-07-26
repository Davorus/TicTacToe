module;

#include <iostream>

export module GUI_Utils;

export namespace GUI
{
    void print(std::string s)
    {
        std::cout << "May it be working?" << std::endl;
    }
}