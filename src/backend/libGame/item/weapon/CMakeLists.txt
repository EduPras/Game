cmake_minimum_required(VERSION 3.18)
project(weapon CXX)
add_library(weapon)
target_sources(
  weapon
  PUBLIC 
        weapon.hpp
        rod/rod.hpp
        sword/sword.hpp
  PRIVATE 
        sword/sword.cpp
        rod/rod.cpp
)

target_include_directories(
  weapon
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
