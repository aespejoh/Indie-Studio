//
// Created by arnau on 17/05/2021.
//

#include "InputModule/inputHandler.hpp"

InputHandler::InputHandler(MessageBus *msgBus) : MsgNode(msgBus)
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
    for (const auto &item : _keyBinds) {
        if (IsKeyDown(item.first))
            send(Msg(item.second));
    }
}

void InputHandler::addKeybind(int keycode, msgType action)
{
    _keyBinds.emplace_back(keycode, action);
}
