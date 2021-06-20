/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "Core/gameLogic.hpp"

GameLogic::GameLogic(MessageBus *msgBus)
 : MsgNode(msgBus)
{
    _players.push_back(_player1);
    _players.push_back(_player2);
    _players.push_back(_player3);
    _players.push_back(_player4);
}

void GameLogic::onNotify(Msg message)
{
    if (_player1 != nullptr) {
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
        case PLACE_BOMB:
            if (_bombCooldown1 == 0) {
                add_bomb(new Bomba(_player1->getPosition(), bombModel));
                _bombCooldown1 = 50;
            }
            break;
        default:
            break;
        }
    }
    if (_player2 != nullptr) {
        switch (message.getType()) {
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
            break;
        case PLA2_PLACE_BOMB:
            if (_bombCooldown2 == 0) {
                add_bomb(new Bomba(_player2->getPosition(), bombModel));
                _bombCooldown2 = 50;
            }
        default:
            break;
        }
    }
}

void GameLogic::updateAI() const
{
    _player3->update();
    _player4->update();
}

void GameLogic::update()
{
    int ret = 0;
    _bombCooldown1 != 0 ? _bombCooldown1-- : _bombCooldown1;
    _bombCooldown2 != 0 ? _bombCooldown2-- : _bombCooldown2;
    for (auto i = _bombs.begin(); i > _bombs.end(); ++i) {
        if (*i == nullptr)
            _bombs.erase(i);
    }
    for (auto &item : _bombs)
        if (item != nullptr) {
            if (item->update()) {
                item->explode();
                ret = _map->destroy(item->getPosition());
                delete item;
                item = nullptr;
            }
        }
    switch (ret) {
        case Player1:
            delete _player1;
            _player1 = nullptr;
            break;
        case Player2:
            delete _player2;
            _player2 = nullptr;
            break;
        case Player3:
            delete _player3;
            _player3 = nullptr;
            break;
        case Player4:
            delete _player4;
            _player4 = nullptr;
            break;
        default:
            break;
    }
}

void GameLogic::add_bomb(Bomba *bomb)
{
    _bombs.push_back(bomb);
}

const std::vector<Bomba *> &GameLogic::getBombs() const
{
    return _bombs;
}

BombModel *GameLogic::getBombModel()
{
    return &bombModel;
}

void GameLogic::loadMap(MapModule *map)
{
    _map = map;
}

void GameLogic::damage(Vector3 bombPosition)
{
    Vector3 pos = bombPosition;
    for (int i = 0; _map->cellType(pos) != MapCell::Wall; i++)
    {
        for (auto &item : _players) {
            if (pos.x == item->getPosition().x && pos.y == item->getPosition().y) {

            }
        }
    }
}
