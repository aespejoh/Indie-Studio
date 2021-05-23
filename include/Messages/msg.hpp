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

enum msgType{
    OPEN_INVENTORY,
    PAUSE_GAME,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};


class Msg {
    public:
        explicit Msg(msgType type) : _type(type) {};
        ~Msg() = default;
        void setType(msgType type) {_type = type;};
        msgType getType() {return _type;};
        int getKeyCode() const { return _keyCode;}
        void setKeyCode(int keyCode) { _keyCode = keyCode; };
        void printType();

    private:
        msgType _type;
        int _keyCode = 0;
};

#endif //INDIE_STUDIO_MSG_HPP
