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
        void exitMouseCheck();

    private:
        Core *core;
        Font font;
        Texture2D exitButton;
        float exitFrameHeight = 0.0;
        Rectangle exitSourceRec = {0, 0, 0, 0};
        int exitState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        bool exitAction = false;
        Vector2 mousePoint = { 0.0f, 0.0f };
        Rectangle exitBtnBounds = {0, 0, 0, 0};;
};

#endif /* !GAMEOVER_HPP_ */
