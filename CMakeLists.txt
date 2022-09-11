cmake_minimum_required(VERSION 3.23)
project(pyatnashki)

set(CMAKE_CXX_STANDARD 14)

add_executable(pyatnashki main.cpp game.h game_field.cpp play_game.cpp check_winner.cpp)