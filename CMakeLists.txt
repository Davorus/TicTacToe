cmake_minimum_required(VERSION 3.8)

set(This TicTacToe)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(Testing/lib/googletest)

set(Headers
    Handler/Playfield_Handler.hpp
    Player/Player.hpp
    Handler/Game_Handler.hpp
    Handler/Gamesetup_Handler.hpp
    Player/Human_Player.hpp
    Player/Random_Bot.hpp
    Player/Smart_Bot.hpp
)

set(Sources
    Handler/Playfield_Handler.cpp
    Player/Player.cpp
    Handler/Game_Handler.cpp
    Handler/Gamesetup_Handler.cpp
    Player/Human_Player.cpp
    Player/Random_Bot.cpp
    Player/Smart_Bot.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(Testing/test)