/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_MESSAGEBUS_HPP
#define INDIE_STUDIO_MESSAGEBUS_HPP

#include <vector>
#include <queue>
#include <functional>
#include <iostream>
#include "msg.hpp"

class MessageBus {
    public:
        MessageBus() = default;
        ~MessageBus() = default;
    void addReceiver(std::function<void (Msg)> messageReceiver);
    void sendMessage(Msg message);
    void notify();
    private:
        std::vector<std::function<void (Msg)>> _receivers;
        std::queue<Msg> _messages;
};

#endif //INDIE_STUDIO_MESSAGEBUS_HPP
