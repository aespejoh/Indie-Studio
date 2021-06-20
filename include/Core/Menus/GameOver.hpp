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
#define NUM_FRAMES 2

class GameOver {
    public:
        GameOver(Core *core);
        ~GameOver();
        Menu menu();
        void loadTextures();
        void initInfo();
        void playMouseCheck();

    private:
        Core *core;
        Font font;
        Texture2D playButton;
        float playFrameHeight = 0.0;
        Rectangle playSourceRec = {0, 0, 0, 0};
        int playState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        bool playAction = false;
        Vector2 mousePoint = { 0.0f, 0.0f };
        Rectangle playBtnBounds = {0, 0, 0, 0};;
};

#endif /* !GAMEOVER_HPP_ */
