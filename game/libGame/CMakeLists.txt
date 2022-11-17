cmake_minimum_required(VERSION 3.18)
project(libgame CXX)
add_library(libgame)

# subfolders
add_subdirectory(item)
add_subdirectory(stage)
add_subdirectory(character)

target_link_libraries(
  libgame
  PRIVATE
    character
    item
    stage
)
include_directories(${root_SOURCE_DIR})

target_include_directories(
  libgame
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
) 
