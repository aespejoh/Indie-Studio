/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "Core/gameLogic.hpp"

GameLogic::GameLogic(MessageBus *msgBus) : MsgNode(msgBus)
{

}

void GameLogic::onNotify(Msg message)
{
    switch (message.getType()) {
    case MOVE_UP:
        _player1->moveUp();
        break;
    case MOVE_DOWN:
        _player1->moveDown();
        break;
    case MOVE_LEFT:
        _player1->moveLeft();
        break;
    case MOVE_RIGHT:
        _player1->moveRight();
        break;
    case PLA2_MOVE_UP:
        _player2->moveUp();
        break;
    case PLA2_MOVE_DOWN:
        _player2->moveDown();
        break;
    case PLA2_MOVE_LEFT:
        _player2->moveLeft();
        break;
    case PLA2_MOVE_RIGHT:
        _player2->moveRight();
        break;
    case PLACE_BOMB:
        add_bomb(new Bomb(_player1->getPosition()));
    case PLA2_PLACE_BOMB:
        add_bomb(new Bomb(_player2->getPosition()));
    default:
        break;
    }
}

void GameLogic::update()
{

}

void GameLogic::add_bomb(Bomb *bomb)
{
    _bombs.push_back(bomb);
}

const std::vector<Bomb *> &GameLogic::getBombs() const
{
    return _bombs;
}
