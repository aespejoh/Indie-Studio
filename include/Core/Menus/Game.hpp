/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Core.hpp"

class Game {
    public:
        explicit Game(Core *core);
        ~Game();
        Menu menu();
    private:
        Menu is_gameover();
        Core *_core;
        Vector3 mapPosition = { -16.0f, 0.0f, -8.0f };
    Model _model;
    Texture _texture;
};

#endif /* !GAME_HPP_ */
