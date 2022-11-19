cmake_minimum_required(VERSION 3.18)
project(app CXX)
add_executable(app)
add_subdirectory(libGame)
target_sources(
    app
    PRIVATE
        main.cpp
)
target_link_libraries(
  app
  PRIVATE
    libgame
)
include_directories(${root_SOURCE_DIR})
