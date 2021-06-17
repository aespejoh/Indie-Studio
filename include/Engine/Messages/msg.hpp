/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_MSG_HPP
#define INDIE_STUDIO_MSG_HPP

#include <map>
#include <iostream>
#include <string>

enum msgType {
    OPEN_INVENTORY,
    PAUSE_GAME,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    PLA2_MOVE_UP,
    PLA2_MOVE_DOWN,
    PLA2_MOVE_LEFT,
    PLA2_MOVE_RIGHT,
    PLACE_BOMB,
    PLA2_PLACE_BOMB
};


class Msg {
    public:
        explicit Msg(msgType type) : _type(type) {};
        ~Msg() = default;
        void setType(msgType type) {_type = type;};
        msgType getType() {return _type;};
        void printType();

    private:
        msgType _type;
};

#endif //INDIE_STUDIO_MSG_HPP
