cmake_minimum_required(VERSION 3.18)
project(stage CXX)
add_library(stage)

target_sources(
  stage
  PUBLIC 
    stage.hpp
  PRIVATE
    stage.cpp
)

target_include_directories(
  stage 
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
