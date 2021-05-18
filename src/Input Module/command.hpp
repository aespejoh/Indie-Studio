/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_COMMAND_HPP
#define INDIE_STUDIO_COMMAND_HPP

#include "messageBus.hpp"

class Command {
    public:
        virtual ~Command() = default;
        virtual void execute() = 0;
};

class MoveCommand: public Command{
    public:
        void execute() override;
};

#endif //INDIE_STUDIO_COMMAND_HPP
