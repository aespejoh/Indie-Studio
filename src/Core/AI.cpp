/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Player AI
*/

#include <Core/AI.hpp>
#include <Bomba.hpp>

AI::AI(int playerID, MapModule *map, MessageBus *bus) : Player(playerID, map), MsgNode(bus)
{
    dir = Direction::LEFT;
    travelled = 0;
    bombCooldown = 0;
}

std::pair<bool, int> AI::nearbyTarget()
{
    Vector3 pos = _position;
    bool obstacle = true;
    int cellType;

    switch(dir) {
        case (UP):
            pos.z -= 0.5;
            cellType = _map->cellType(pos);
            obstacle = _map->canPass(pos, _position, _player_ID);
            break;
        case DOWN:
            pos.z += 0.5;
            cellType = _map->cellType(pos);
            obstacle = _map->canPass(pos, _position, _player_ID);
            break;
        case LEFT:
            pos.x -= 0.5;
            cellType = _map->cellType(pos);
            obstacle = _map->canPass(pos, _position, _player_ID);
            break;
        case RIGHT:
            pos.x += 0.5;
            cellType = _map->cellType(pos);
            obstacle = _map->canPass(pos, _position, _player_ID);
            break;
        case STEADY:
            cellType = Empty;
            obstacle = _map->canPass(pos, _position, _player_ID);
            break;
    }
    return (std::make_pair(!obstacle, cellType));
}

bool AI::goodDirection(Vector3 pos, Direction direction)
{
    switch(direction) {
        case (UP):
            pos.z -= 0.5;
            break;
        case LEFT:
            pos.x -= 0.5;
            break;
        case DOWN:
            pos.z += 0.5;
            break;
        case RIGHT:
            pos.x += 0.5;
            break;
        default:
            return (false);
    }
    if (_map->canPass(pos, _position, _player_ID)) {
        dir = direction;
        return (true);
    }
    return (false);
}

void AI::changeDirection()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 3);
    int direction = dist(mt);
    std::vector<bool> visited = {false, false, false, false};
    bool found = false;
    Vector3 pos = _position;

    for (int i = 0; i < 4 && !found; direction = dist(mt)) {
        switch(direction) {
            case (UP):
                if (!visited[0]) {
                    ++i;
                    visited[0] = true;
                    if (dir == UP)
                        break;
                    found = goodDirection(pos, UP);
                }
                break;
            case (LEFT):
                if (!visited[1]) {
                    ++i;
                    visited[1] = true;
                    if (dir == LEFT) {
                        break;
                    }
                    found = goodDirection(pos, LEFT);
                }
                break;
            case (DOWN):
                if (!visited[2]) {
                    ++i;
                    visited[2] = true;
                    if (dir == DOWN)
                        break;
                    found = goodDirection(pos, DOWN);
                }
                break;
            case (RIGHT):
                if (!visited[3]) {
                    ++i;
                    visited[3] = true;
                    if (dir == RIGHT)
                        break;
                    found = goodDirection(pos, RIGHT);
                }
                break;
            default:
                dir = UP;
        }
    }
}

void AI::moveAI()
{
    travelled += 0.1;
    switch (dir) {
        case UP:
            moveUp();
            break;
        case (DOWN):
            moveDown();
            break;
        case (LEFT):
            moveLeft();
            break;
        case (RIGHT):
            moveRight();
            break;
    }
}

bool AI::randomMovement()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(30.0, 60.0);

    if (travelled >= dist(mt)) {
        changeDirection();
        travelled = 0;
        return (true);
    }
    return (false);
}

void AI::setBomb()
{
    if (bombCooldown == 0) {
        if (_player_ID == 3)
            send(Msg(PLA3_PLACE_BOMB));
        else if (_player_ID == 4)
            send(Msg(PLA4_PLACE_BOMB));
        bombCooldown = 50;
    }

}

void AI::update()
{
    std::pair<bool, int>nearby = nearbyTarget();
    bombCooldown != 0 ? bombCooldown-- : bombCooldown;

    if (randomMovement())
        return;
    if (nearby.first) {
        if (nearby.second == Box)
            setBomb();
        else if (nearby.second != Empty) {
            changeDirection();
        }
    }
    moveAI();
}
