cmake_minimum_required(VERSION 3.8)

set(This SmartBotTesting)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(lib/googletest)

set(Headers
    src/PreSmartBot.hpp
    src/Random_Bot.hpp
    src/Playfield_Handler.hpp)

set(Sources
    src/PreSmartBot.cpp
    src/Random_Bot.cpp
    src/Playfield_Handler.cpp)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)