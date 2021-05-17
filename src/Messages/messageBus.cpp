/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "Messages/messageBus.hpp"

void MessageBus::addReciever(std::function<void(Msg)> messageReceiver)
{
    _receivers.push_back(messageReceiver);
}

void MessageBus::sendMessage(Msg message)
{
    _messages.push(message);
}

void MessageBus::notify()
{
    while (!_messages.empty()) {
        for (auto & _receiver : _receivers) {
            _receiver(_messages.front());
        }
        _messages.pop();
    }
}
