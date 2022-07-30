cmake_minimum_required(VERSION 3.18)
project(ring CXX)
add_library(ring)
target_sources(
  ring
  PUBLIC 
        ring.hpp
        shadow/shadow.hpp
        rock/rock.hpp
  PRIVATE 
        rock/rock.cpp
        shadow/shadow.cpp
)

target_include_directories(
  ring
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
