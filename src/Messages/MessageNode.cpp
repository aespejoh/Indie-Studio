/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "MessageNode.hpp"

MessageNode::MessageNode(MessageBus *bus) : _bus(bus)
{
    _bus->addReceiver(getNotifyFunc());
}

std::function<void(Msg)> MessageNode::getNotifyFunc()
{
    auto listener = [=] (Msg message) -> void {
        this->onNotify(message);
    };
    return listener;
}

void MessageNode::onNotify(Msg message)
{
    std::cout << "onNotifyNotImplemented";
}

void MessageNode::send(Msg message)
{
    _bus->sendMessage(message);
}
