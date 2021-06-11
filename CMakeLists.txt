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
        src/Core/gameLogic.cpp
        include/Engine/Messages/MsgNode.hpp
        include/Engine/Messages/messageBus.hpp
        include/Engine/InputModule/inputHandler.hpp
        include/Engine/Messages/msg.hpp
        include/Core/gameLogic.hpp
        src/Engine/console.cpp
        include/Engine/console.hpp
        src/Engine/Messages/renderModule.cpp
        include/Engine/Objects/renderModule.hpp
        src/Engine/Messages/cameraModule.cpp
        include/Engine/cameraModule.hpp src/Engine/Objects/Object.cpp
        include/Engine/Objects/Object.hpp
        src/Engine/Objects/RenderComponent.cpp
        include/Engine/Messages/RenderComponent.hpp
        src/Engine/Objects/BaseComponent.cpp
        include/Engine/Objects/BaseComponent.hpp
        include/Engine/Messages/CollisionBox.cpp
        include/Engine/Messages/CollisionBox.hpp
        src/Engine/SceneManager.cpp
        include/Engine/SceneManager.hpp
        include/Core/gameLogic.hpp
        include/Engine/SoundModule/SoundHandler.hpp)

include_directories(./include include/Engine/Messages include/Core include/Engine include/Engine/InputModule)
find_package(raylib REQUIRED)
target_link_libraries(bomberman raylib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})