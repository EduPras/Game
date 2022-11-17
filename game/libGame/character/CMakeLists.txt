cmake_minimum_required(VERSION 3.18)
project(character CXX)
add_library(character)

target_sources(
  character
  PUBLIC 
    character.hpp
    characters.hpp
    hero/hero.hpp
    enemy/enemy.hpp
  PRIVATE
    character.cpp
    hero/hero.cpp
    enemy/enemy.cpp
)

target_include_directories(
  character
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
