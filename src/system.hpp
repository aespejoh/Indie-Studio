/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_SYSTEM_HPP
#define INDIE_STUDIO_SYSTEM_HPP

#include "messageBus.hpp"

class System {
    public:
        System(MessageBus *bus);
        Msg getMessage();
    private:
        MessageBus *_bus;
};

#endif //INDIE_STUDIO_SYSTEM_HPP
