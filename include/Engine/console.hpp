/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_CONSOLE_HPP
#define INDIE_STUDIO_CONSOLE_HPP

#include "MessageNode.hpp"

class Console {
    public:
        Console();
        void update();
    protected:
        std::string _command;

};

#endif //INDIE_STUDIO_CONSOLE_HPP
