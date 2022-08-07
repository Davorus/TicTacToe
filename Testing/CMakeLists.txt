cmake_minimum_required(VERSION 3.8)

set(This TicTacToe)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(lib/googletest)

set(Headers

)

set(Sources

)

add(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)