cmake_minimum_required(VERSION 3.8)

set(This gameTest)

set(Sources
    SmartBotTesting.cpp)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    Testing)

add_test(
    Name ${This}
    COMMAND ${This}
)