cmake_minimum_required(VERSION 3.8)

set(This SmartBotTesting)

set(Sources
    SmartBotTesting.cpp
    Random_Bot.cpp
    Playfield_Handler.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    testing)

add_test(
    Name ${This}
    COMMAND ${This}
)