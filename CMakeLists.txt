cmake_minimum_required (VERSION 3.11)
 
# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)
 
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  # Important: Specify a GIT_TAG XXXXX here.
)
 
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
 
# ------------------------------------------------------------------------------
add_subdirectory(src/backend)

project(
  ftxui-starter
  LANGUAGES CXX
  VERSION 1.0.0
)
 
add_executable(ftxui-starter src/frontend/main.cpp)
#add_executable(ftxui-starter src/backend/main.cpp)
target_include_directories(
  ftxui-starter 
  PRIVATE 
    src
  )
 
target_link_libraries(
  ftxui-starter
  PRIVATE 
    ftxui::screen
    ftxui::dom
    ftxui::component # Not needed for this example.
    app
)