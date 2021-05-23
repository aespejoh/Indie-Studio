/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "gameLogic.hpp"

GameLogic::GameLogic(MessageBus *msgBus) : MessageNode(msgBus)
{

}

void GameLogic::onNotify(Msg message)
{
    std::cout << message.getType();
    if (message.getKeyCode() == MOVE_DOWN) std::cout << "move down" << std::endl;
    if (message.getKeyCode() == MOVE_UP) std::cout << "move up" << std::endl;
    if (message.getKeyCode() == MOVE_LEFT) std::cout << "move left" << std::endl;
    if (message.getKeyCode() == MOVE_RIGHT) std::cout << "move right" << std::endl;
}
