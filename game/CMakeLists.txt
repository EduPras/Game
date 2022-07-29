cmake_minimum_required(VERSION 3.18)
project(game CXX)
add_executable(game)
add_subdirectory(libGame)
target_sources(
    game
    PRIVATE
        main.cpp
)
target_link_libraries(
  game
  PRIVATE
    libgame
)
include_directories(${root_SOURCE_DIR})
