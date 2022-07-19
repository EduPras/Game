cmake_minimum_required(VERSION 3.18)
project(game CXX)
add_executable(game)
target_sources(
    game
    PRIVATE
        libGame/character/character.hpp
        libGame/character/character.cpp
        libGame/item/item.hpp
        libGame/item/item.cpp
        main.cpp
)
include_directories(${root_SOURCE_DIR})