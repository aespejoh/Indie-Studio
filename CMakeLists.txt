cmake_minimum_required(VERSION 3.17.4)
project(indie_studio)
set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
add_executable(indie_studio
        src/main.cpp src/scene.cpp include/scene.hpp src/Messages/MessageNode.cpp include/Messages/MessageNode.hpp src/Messages/messageBus.cpp include/Messages/messageBus.hpp "src/Input Module/inputHandler.cpp" include/InputModule/inputHandler.hpp src/Messages/msg.cpp include/Messages/msg.hpp "src/gameLogic.cpp" "include/gameLogic.hpp")

include_directories(./include ./include/Messages)
find_package(raylib REQUIRED)
target_link_libraries(indie_studio raylib)