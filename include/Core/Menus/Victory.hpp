/*
** EPITECH PROJECT, 2021
** Victory.hpp.h
** File description:
** Victory.hpp.h
*/
#ifndef BOMBERMAN_VICTORY_HPP
#define BOMBERMAN_VICTORY_HPP

#include "Core.hpp"

#define WIDTH 1000
#define HEIGHT 750
#define NUM_FRAMES 2

class Victory {
    public:
        Victory(Core *core);
        ~Victory();
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

#endif //BOMBERMAN_VICTORY_HPP
