cmake_minimum_required(VERSION 3.24)
project(Fillgame)

set(CMAKE_CXX_STANDARD 17)

add_executable(Fillgame main.cpp src/game_basics.h src/Move.cpp src/Move.h src/Fillgame.cpp src/Fillgame.h)
