cmake_minimum_required(VERSION 3.17.4)
project(indie_studio)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
find_package(raylib REQUIRED)
add_executable(indie_studio
        src/main.cpp src/scene.cpp include/scene.hpp)

include_directories(./include)

target_link_libraries(indie_studio raylib)