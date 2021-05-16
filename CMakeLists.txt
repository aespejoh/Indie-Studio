cmake_minimum_required(VERSION 3.19)
project(indie_studio)

set(CMAKE_CXX_STANDARD 14)
find_package(raylib 2.5.0 REQUIRED) # Requires at least version 2.5.0

add_executable(indie_studio
        src/main.cpp src/scene.cpp include/scene.hpp)

include_directories(include)

target_link_libraries(indie_studio raylib)