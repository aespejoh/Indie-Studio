cmake_minimum_required(VERSION 3.17.4)
project(bomberman)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
add_executable(bomberman
        src/main.cpp
        src/Engine/Messages/MessageNode.cpp
        src/Engine/Messages/messageBus.cpp
        src/Engine/InputModule/inputHandler.cpp
        src/Engine/Messages/msg.cpp
        src/Engine/SoundModule/SoundHandler.cpp
        src/Engine/CameraModule/CameraHandler.cpp
        src/Engine/MapModule/MapModule.cpp
        src/Core/gameLogic.cpp
        src/Core/Core.cpp
        include/Engine/Messages/MessageNode.hpp
        include/Engine/Messages/messageBus.hpp
        include/Engine/InputModule/inputHandler.hpp
        include/Engine/CameraModule/CameraHandler.hpp
        include/Engine/Messages/msg.hpp
        include/Engine/MapModule/mapModule.h
        include/Core/gameLogic.hpp
        include/Core/Core.hpp
        include/Engine/SoundModule/SoundHandler.hpp)

include_directories(./include include/Engine/Messages include/Core include/Engine include/Engine/InputModule)
find_package(raylib REQUIRED)
target_link_libraries(bomberman raylib)