cmake_minimum_required(VERSION 3.18)
project(item CXX)
add_library(item)

# subfolders
add_subdirectory(weapon)
add_subdirectory(ring)

target_sources(
  item
  PUBLIC 
    item.hpp
    items.hpp
  PRIVATE
    item.cpp
)


target_link_libraries(
  item
  PRIVATE
    weapon
    ring
  )

target_include_directories(
  item
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
