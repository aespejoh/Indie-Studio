//
// Created by arnau on 17/05/2021.
//

#include "inputHandler.hpp"

InputHandler::InputHandler(MessageBus *msgBus) : MessageNode(msgBus)
{
}

void InputHandler::onNotify(Msg message)
{
    std::cout << "Input Received" << message.getType() << std::endl;
}

void InputHandler::update()
{
    Msg message(PAUSE_GAME);
    send(message);
}
