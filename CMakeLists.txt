cmake_minimum_required(VERSION 3.17.4)
project(bomberman)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
add_executable(bomberman
        src/main.cpp
        src/Engine/Messages/MessageNode.cpp
        src/Engine/Messages/messageBus.cpp
        src/Engine/InputModule/inputHandler.cpp
        src/Engine/Messages/msg.cpp
        src/Core/gameLogic.cpp
        include/Engine/Messages/MessageNode.hpp
        include/Engine/Messages/messageBus.hpp
        include/Engine/InputModule/inputHandler.hpp
        include/Engine/Messages/msg.hpp
        include/Core/gameLogic.hpp
        src/Engine/console.cpp
        include/Engine/console.hpp
        src/Engine/Messages/renderModule.cpp
        src/Engine/Messages/renderModule.hpp
        src/Engine/Messages/cameraModule.cpp
        src/Engine/Messages/cameraModule.hpp)

include_directories(./include include/Engine/Messages include/Core include/Engine include/Engine/InputModule)
find_package(raylib REQUIRED)
target_link_libraries(bomberman raylib)