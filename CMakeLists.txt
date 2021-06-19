cmake_minimum_required(VERSION 3.17.4)
project(bomberman)
set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
add_executable(bomberman
        src/Core/Menus/Game.cpp
        src/Core/Menus/GameOver.cpp
        src/Core/Menus/MainMenu.cpp
        src/Core/Menus/Mid.cpp
        src/Core/Menus/Settings.cpp
        src/Core/Core.cpp
        src/Engine/MapModule/MapModule.cpp
        src/Core/gameLogic.cpp
        src/Engine/CameraModule/CameraHandler.cpp
        src/Engine/InputModule/inputHandler.cpp
        src/Engine/Messages/MsgNode.cpp
        src/Engine/Messages/messageBus.cpp
        src/Engine/Messages/msg.cpp
        src/Engine/Objects/BaseComponent.cpp
        src/Engine/Objects/Object.cpp
        src/Engine/Objects/RenderComponent.cpp
        src/Engine/RenderModule/renderModule.cpp
        src/Engine/SoundModule/SoundHandler.cpp
        src/Engine/console.cpp
        src/Engine/SceneManager.cpp
        src/main.cpp
        include/Core/Menus/Game.hpp
        include/Engine/MapModule/mapModule.h
        include/Core/Menus/GameOver.hpp
        include/Core/Menus/MainMenu.hpp
        include/Core/Menus/Mid.hpp
        include/Core/Menus/Settings.hpp
        include/Core/Core.hpp
        include/Core/gameLogic.hpp
        include/Core/Menus.hpp
        include/Engine/CameraModule/CameraHandler.hpp
        include/Engine/InputModule/inputHandler.hpp
        include/Engine/Messages/messageBus.hpp
        include/Engine/Messages/msg.hpp
        include/Engine/Messages/MsgNode.hpp
        include/Engine/Objects/BaseComponent.hpp
        include/Engine/Objects/Object.hpp
        include/Engine/Objects/RenderComponent.hpp
        include/Engine/Objects/renderModule.hpp
        include/Engine/SoundModule/SoundHandler.hpp
        include/Engine/console.hpp
        include/Engine/SceneManager.hpp
        src/Core/Player.cpp
        include/Core/Player.hpp
        src/Core/Menus/Bomba.cpp
        include/Core/Bomba.hpp)
include_directories(./include include/Engine/Messages include/Core
        include/Engine include/Engine/InputModule include/Core/Menus include/Engine/Objects)
find_package(raylib REQUIRED)
target_link_libraries(bomberman raylib)