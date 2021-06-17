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
        if (_bombCooldown1 == 0) {
            add_bomb(new Bomb(_player1->getPosition(), bombModel));
            _bombCooldown1 = 50;
        }
    case PLA2_PLACE_BOMB:
        if (_bombCooldown2 == 0) {
            add_bomb(new Bomb(_player2->getPosition(), bombModel));
            _bombCooldown2 = 50;
        }
    default:
        break;
    }
}

void GameLogic::update()
{
    _bombCooldown1 != 0 ? _bombCooldown1-- : _bombCooldown1;
    _bombCooldown2 != 0 ? _bombCooldown2-- : _bombCooldown2;
}

void GameLogic::add_bomb(Bomb *bomb)
{
    _bombs.push_back(bomb);
}

const std::vector<Bomb *> &GameLogic::getBombs() const
{
    return _bombs;
}

BombModel *GameLogic::getBombModel()
{
    return &bombModel;
}
