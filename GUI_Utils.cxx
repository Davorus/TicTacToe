module;

#include <iostream>

export module GUI_Utils;

export namespace GUI
{
    void print(std::string s)
    {
        std::cout << s << std::endl;
    }
}