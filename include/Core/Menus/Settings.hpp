/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "Core.hpp"

#define WIDTH 1000
#define HEIGHT 750
#define NUM_FRAMES 2

class Settings {
    public:
        Settings(Core *core);
        ~Settings();
        Menu menu();
        void loadTexture();
        void checkMouse();
        void loadRect();
        void drawing();
        void drawingMusicVolumen();
        void drawingFpds();
        void drawButton();
        void playMouseCheck();
        void initInfo();
        void switchFpsAsc();
        void switchFpsDes();

    protected:
        Core *core;
        Font font;
        Texture2D background;
        Texture2D arrow_left;
        Texture2D arrow_right;
        Texture2D playButton;
        Vector2 mousePoint = { 0.0f, 0.0f };
        Rectangle arrow_left_rect = {0, 0, 0, 0};
        Rectangle arrow_right_rect = {0, 0, 0, 0};
        Rectangle arrow_left_rect_ = {0, 0, 0, 0};
        Rectangle arrow_right_rect_ = {0, 0, 0, 0};
        float playFrameHeight = 0.0;
        Rectangle playBtnBounds = {0, 0, 0, 0};
        Rectangle playSourceRec = {0, 0, 0, 0};
        int playState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        bool playAction = false;
    private:
};

#endif /* !SETTINGS_HPP_ */
