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
        Game(Core *core);
        ~Game();
        Menu menu();
    private:
        Core *_core;
};

#endif /* !GAME_HPP_ */
