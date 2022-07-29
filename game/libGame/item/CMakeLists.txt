cmake_minimum_required(VERSION 3.18)
project(item CXX)
add_library(item)
add_subdirectory(weapon)
target_sources(
  item
  PUBLIC 
    item.hpp
    items.hpp
)


target_link_libraries(
  item
  PRIVATE
    weapon
  )

target_include_directories(
  item
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
