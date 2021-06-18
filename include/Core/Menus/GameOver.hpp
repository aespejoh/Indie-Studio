/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** GameOver
*/

#ifndef GAMEOVER_HPP_
#define GAMEOVER_HPP_

#include "Core.hpp"

#define WIDTH 1000
#define HEIGHT 750

class GameOver {
    public:
        GameOver(Core *core);
        ~GameOver();
        Menu menu();

    private:
        Core *core;
        Font font;
};

#endif /* !GAMEOVER_HPP_ */
