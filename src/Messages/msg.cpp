/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "msg.hpp"

std::ostream &operator<<(std::ostream &os, const msgType msg)
{
    static std::map<msgType, std::string> strings;
    if (strings.empty()) {
        #define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(OPEN_INVENTORY);
        INSERT_ELEMENT(PAUSE_GAME);
        INSERT_ELEMENT(MOVE_UP);
        INSERT_ELEMENT(MOVE_DOWN);
        INSERT_ELEMENT(MOVE_LEFT);
        INSERT_ELEMENT(MOVE_RIGHT);
        #undef INSERT_ELEMENT
    }
    return os << strings[msg];
}

void Msg::printType()
{
    std::cout << _type;
}
