cmake_minimum_required(VERSION 3.17.5)
project(bomberman)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
find_package(raylib REQUIRED)
add_executable(bomberman
        src/main.cpp src/scene.cpp include/scene.hpp)

include_directories(./include)

target_link_libraries(bomberman raylib)