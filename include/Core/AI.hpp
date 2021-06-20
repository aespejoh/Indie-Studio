/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Player AI
*/

#ifndef BOMBERMAN_AI_HPP
#define BOMBERMAN_AI_HPP

#include <Core/Player.hpp>

class AI : public Player {
public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STEADY
    };

    explicit AI(int, MapModule &);
    void update();

private:
    Direction dir;
    float travelled;

    std::pair<bool, int> nearbyTarget();
    void changeDirection();
    void moveAI();
    bool randomMovement();
    bool goodDirection(Vector3 pos, Direction direction);

};
#endif //BOMBERMAN_AI_HPP
