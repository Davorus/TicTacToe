cmake_minimum_required(VERSION 3.8)

set(This TicTacToeTest)

set(Sources

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