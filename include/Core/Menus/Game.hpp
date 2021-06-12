/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Parameters.hpp"

class Game {
    public:
        Game(Parameters &parameters);
        ~Game();
    private:
        Parameters parameters;
};

#endif /* !GAME_HPP_ */
