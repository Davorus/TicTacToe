cmake_minimum_required(VERSION 3.8)

set(This TicTacToeTest)

set(Sources
    TicTacToeTest.cpp
    ../../Player/Player.cpp
    ../../Player/Random_Bot.cpp
    ../../Player/Smart_Bot.cpp
    ../../Handler/Playfield_Handler.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    gtest
)

add_test(
    NAME ${This}
    COMMAND ${This}
)