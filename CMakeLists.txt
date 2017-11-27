cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h GameFlow.cpp GameFlow.h GameLogic.cpp GameLogic.h Position.cpp Position.h HumanPlayer.cpp HumanPlayer.h Player.cpp Player.h AIplayer.cpp AIplayer.h)
add_executable(untitled ${SOURCE_FILES})