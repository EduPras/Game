cmake_minimum_required(VERSION 3.18)
project(libgame CXX)
add_library(libgame)
target_sources(
  libgame
  PUBLIC 
        character/character.hpp
        item/weapon/weapon.hpp
        item/weapon/rod/rod.hpp
        item/weapon/sword/sword.hpp
  PRIVATE 
        character/character.cpp        
        item/weapon/sword/sword.cpp
        item/weapon/rod/rod.cpp
)

target_include_directories(
  libgame
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
) 
