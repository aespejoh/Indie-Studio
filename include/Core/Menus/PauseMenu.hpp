/*
** EPITECH PROJECT, 2021
** PauseMenu.hpp.h
** File description:
** PauseMenu.hpp.h
*/
#ifndef BOMBERMAN_PAUSEMENU_HPP
#define BOMBERMAN_PAUSEMENU_HPP

#include "Core.hpp"

#define WIDTH 1000
#define HEIGHT 750
#define NUM_FRAMES 2

class PauseMenu {
public:
    explicit PauseMenu(Core *core);
    ~PauseMenu();
    Menu menu();
    void loadTextures();
    void drawings();
    void initInfo();
    void playMouseCheck();
    void optionsMouseCheck();
    void exitMouseCheck();

private:
    Core *core;
    Font font;
    Texture2D background;
    Texture2D playButton;
    Texture2D optionsButton;
    Texture2D exitButton;
    float playFrameHeight = 0.0;
    float optionsFrameHeight = 0.0;
    float exitFrameHeight = 0.0;
    Rectangle playSourceRec = {0, 0, 0, 0};
    Rectangle optionsSourceRec = {0, 0, 0, 0};
    Rectangle exitSourceRec = {0, 0, 0, 0};
    Rectangle playBtnBounds = {0, 0, 0, 0};
    int playState = 0;  // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool playAction = false;     // Button action should be activated
    Rectangle optionsBtnBounds = {0, 0, 0, 0};
    int optionsState = 0;
    bool optionsAction = false;
    Rectangle exitBtnBounds = {0, 0, 0, 0};
    int exitState = 0;
    bool exitAction = false;
    Vector2 mousePoint = { 0.0f, 0.0f };
};

#endif //BOMBERMAN_PAUSEMENU_HPP
