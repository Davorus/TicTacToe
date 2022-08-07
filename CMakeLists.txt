cmake_minimum_required(VERSION 3.8)

set(This TicTacToe)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(Testing/lib/googletest)

set(Headers
    Handler/Game_Handler.hpp
    Handler/Gamesetup_Handler.hpp
    Handler/Playfield_Handler.hpp
)

set(Sources
    Handler/Game_Handler.cpp
    Handler/Gamesetup_Handler.cpp
    Handler/Playfield_Handler.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(Testing/test)