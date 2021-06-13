cmake_minimum_required(VERSION 3.17.4)
project(bomberman)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
add_executable(bomberman
        src/main.cpp
        src/Engine/Messages/MsgNode.cpp
        src/Engine/Messages/messageBus.cpp
        src/Engine/InputModule/inputHandler.cpp
        src/Engine/Messages/msg.cpp
        src/Engine/SoundModule/SoundHandler.cpp
        src/Engine/CameraModule/CameraHandler.cpp
        src/Core/gameLogic.cpp
        include/Engine/Messages/MsgNode.hpp
        src/Core/Core.cpp
        include/Engine/Messages/messageBus.hpp
        include/Engine/InputModule/inputHandler.hpp
        include/Engine/CameraModule/CameraHandler.hpp
        include/Engine/Messages/msg.hpp
        include/Core/gameLogic.hpp
        src/Engine/console.cpp
        include/Engine/console.hpp
        src/Engine/Messages/renderModule.cpp
        include/Engine/Objects/renderModule.hpp
        src/Engine/Objects/Object.cpp
        include/Engine/Objects/Object.hpp
        src/Engine/Objects/RenderComponent.cpp
        include/Engine/Messages/RenderComponent.hpp
        src/Engine/Objects/BaseComponent.cpp
        include/Engine/Objects/BaseComponent.hpp
        src/Engine/SceneManager.cpp
        include/Engine/SceneManager.hpp
        include/Core/gameLogic.hpp
        include/Core/Core.hpp
        src/Core/Menus/Mid.cpp src/Core/Menus/Settings.cpp src/Core/Menus/Game.cpp src/Core/Menus/GameOver.cpp src/Core/Menus/MainMenu.cpp
        include/Engine/SoundModule/SoundHandler.hpp include/Core/Menus/Mid.hpp include/Core/Menus/Settings.hpp include/Core/Menus/Game.hpp include/Core/Menus/GameOver.hpp include/Core/Menus/MainMenu.hpp src/Core/Parameters.cpp include/Core/Parameters.hpp)

include_directories(./include include/Engine/Messages include/Core include/Engine include/Engine/InputModule)
find_package(raylib REQUIRED)
target_link_libraries(bomberman raylib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})