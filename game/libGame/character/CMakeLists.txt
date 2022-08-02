cmake_minimum_required(VERSION 3.18)
project(character CXX)
add_library(character)

target_sources(
  character
  PUBLIC 
    character.hpp
    characters.hpp
    warrior/warrior.hpp
    wizard/wizard.hpp
  PRIVATE
    character.cpp
    warrior/warrior.cpp
    wizard/wizard.cpp
)

target_include_directories(
  character
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
