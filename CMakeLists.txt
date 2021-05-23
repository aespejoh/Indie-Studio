cmake_minimum_required(VERSION 3.17.4)
project(indie_studio)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
add_executable(indie_studio
        src/main.cpp src/Engine/Messages/MessageNode.cpp include/Engine/Messages/MessageNode.hpp src/Engine/Messages/messageBus.cpp include/Engine/Messages/messageBus.hpp "src/Engine/Input Module/inputHandler.cpp" include/Engine/InputModule/inputHandler.hpp src/Engine/Messages/msg.cpp include/Engine/Messages/msg.hpp "src/Core/gameLogic.cpp" "include/Core/gameLogic.hpp")

include_directories(./include include/Engine/Messages include/Core include/Engine include/Engine/InputModule)
find_package(raylib REQUIRED)
target_link_libraries(indie_studio raylib)