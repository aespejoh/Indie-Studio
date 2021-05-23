//
// Created by arnau on 17/05/2021.
//

#include "InputModule/inputHandler.hpp"

InputHandler::InputHandler(MessageBus *msgBus) : MessageNode(msgBus)
{
    addKeybind(KEY_A, MOVE_LEFT);
    addKeybind(KEY_W, MOVE_UP);
    addKeybind(KEY_D, MOVE_RIGHT);
    addKeybind(KEY_S, MOVE_DOWN);
}

void InputHandler::onNotify(Msg message)
{
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
        if (key == item.first)
            send(Msg(item.second));
    }
}

void InputHandler::addKeybind(int keycode, msgType action)
{
    _keyBinds.emplace_back(keycode, action);
}
