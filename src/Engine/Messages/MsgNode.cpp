/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "MsgNode.hpp"

MsgNode::MsgNode(MessageBus *bus) : _bus(bus)
{
    _bus->addReceiver(getNotifyFunc());
}

std::function<void(Msg)> MsgNode::getNotifyFunc()
{
    auto listener = [=] (Msg message) -> void {
        this->onNotify(message);
    };
    return listener;
}

void MsgNode::onNotify(Msg message)
{
    //std::cout << "onNotifyNotImplemented";
}

void MsgNode::send(Msg message)
{
    _bus->sendMessage(message);
}
