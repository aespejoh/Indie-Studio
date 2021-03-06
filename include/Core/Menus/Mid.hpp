/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Mid
*/

#ifndef MID_HPP_
#define MID_HPP_

#include "Core.hpp"

#define WIDTH 1000
#define HEIGHT 750
#define NUM_FRAMES 2

class Mid {
    public:
        explicit Mid(Core *core);
        ~Mid();
        Menu menu();
        void loadModels();
        void loadTextures();
        void drawings();
        void drawModels();
        void drawPlayersInfo();
        void setPositions();
        void drawButton();
        void playMouseCheck();
        void initInfo();
        void checkFiles();
    private:
        Core *core;
        Model boomberman_blue;
        Model boomberman_black;
        Model boomberman_yellow;
        Model boomberman_red;
        Texture2D blue;
        Texture2D black;
        Texture2D yellow;
        Texture2D red;
        Texture2D playButton;
        Texture2D background;
        Vector3 position;
        Vector3 position_two;
        Vector3 position_three;
        Vector3 position_four;
        Font font;
        Vector2 mousePoint = { 0.0f, 0.0f };
        bool arrow = false;
        float playFrameHeight = 0.0;
        Rectangle playBtnBounds = {0, 0, 0, 0};
        Rectangle playSourceRec = {0, 0, 0, 0};
        int playState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
        bool playAction = false;
};

#endif /* !MID_HPP_ */
