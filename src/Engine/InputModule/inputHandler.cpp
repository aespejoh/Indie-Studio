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
    addKeybind(KEY_DOWN, PLA2_MOVE_DOWN);
    addKeybind(KEY_UP, PLA2_MOVE_UP);
    addKeybind(KEY_LEFT, PLA2_MOVE_LEFT);
    addKeybind(KEY_RIGHT, PLA2_MOVE_RIGHT);
    addKeybind(KEY_SPACE, PLACE_BOMB);
    addKeybind(KEY_ENTER, PLA2_PLACE_BOMB);
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
