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

    protected:
        Core *core;
        Font font;
        Texture2D background;
        Texture2D arrow_left;
        Texture2D arrow_right;
        Vector2 mousePoint = { 0.0f, 0.0f };
        Rectangle arrow_left_rect = {0, 0, 0, 0};
        Rectangle arrow_right_rect = {0, 0, 0, 0};
    private:
};

#endif /* !SETTINGS_HPP_ */
