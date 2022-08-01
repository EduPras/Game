cmake_minimum_required(VERSION 3.18)
project(libgame CXX)
add_library(libgame)
add_subdirectory(item)
target_sources(
  libgame
  PUBLIC 
        character/character.hpp
        character/warrior/warrior.hpp
        character/wizard/wizard.hpp
  PRIVATE 
        character/character.cpp        
        character/warrior/warrior.cpp
        character/wizard/wizard.cpp
)
target_link_libraries(
  libgame
  PRIVATE
    item
)
include_directories(${root_SOURCE_DIR})

target_include_directories(
  libgame
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
) 
