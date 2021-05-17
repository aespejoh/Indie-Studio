/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_MESSAGENODE_HPP
#define INDIE_STUDIO_MESSAGENODE_HPP

#include "messageBus.hpp"

class MessageNode {
    public:
        explicit MessageNode(MessageBus *bus);
        virtual void update() {};
    protected:
        std::function<void (Msg)> getNotifyFunc();
        virtual void onNotify(Msg message);
        void send(Msg message);
        MessageBus *_bus;
};

#endif //INDIE_STUDIO_MESSAGENODE_HPP
