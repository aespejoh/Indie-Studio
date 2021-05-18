//
// Created by arnau on 17/05/2021.
//

#include "InputModule/inputHandler.hpp"

InputHandler::InputHandler(MessageBus *msgBus) : MessageNode(msgBus)
{
    _keyBinds.push_back(std::make_pair(KEY_A, MOVE_LEFT));
    _keyBinds.push_back(std::make_pair(KEY_W, MOVE_UP));
    _keyBinds.push_back(std::make_pair(KEY_D, MOVE_RIGHT));
    _keyBinds.push_back(std::make_pair(KEY_S, MOVE_DOWN));
}

void InputHandler::onNotify(Msg message)
{
    std::cout << "Input Received" << message.getType() << std::endl;
}

void InputHandler::update()
{
    int key = GetKeyPressed();
    while (key > 0) { // Process more than one input on the same frame
        handleInput(key);
        key = GetCharPressed();
    }
}

void InputHandler::handleInput(int key)
{
    for (const auto &item : _keyBinds) {
        send(Msg(item.second));
    }
}
