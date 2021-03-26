cmake_minimum_required(VERSION 3.17)
project(2048Console)

set(CMAKE_CXX_STANDARD 14)

add_executable(2048Console main.cpp Board.cpp Board.h Game.cpp Game.h)