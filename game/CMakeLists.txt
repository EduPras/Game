cmake_minimum_required(VERSION 3.18)
project(game CXX)
add_executable(game)
target_sources(
    game
    PRIVATE
        libGame/item/item.hpp
        libGame/item/items.hpp
        libGame/character/character.hpp
        libGame/character/character.cpp        
        libGame/item/weapon/weapon.hpp
        libGame/item/weapon/rod/rod.hpp
        libGame/item/weapon/rod/rod.cpp
        libGame/item/weapon/sword/sword.hpp
        libGame/item/weapon/sword/sword.cpp
        main.cpp
)
include_directories(${root_SOURCE_DIR})