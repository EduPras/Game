cmake_minimum_required(VERSION 3.18)
project(game CXX)
add_library(game)

target_sources(
  game 
  PUBLIC 
    game.hpp
  PRIVATE
    game.cpp
)

target_include_directories(
  game 
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
