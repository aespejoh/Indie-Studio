/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "Core/gameLogic.hpp"

GameLogic::GameLogic(MessageBus *msgBus) : MessageNode(msgBus)
{

}

void GameLogic::onNotify(Msg message)
{
    message.printType();
}
