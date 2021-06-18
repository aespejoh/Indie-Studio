/*
** EPITECH PROJECT, 2021
** PauseMenu.cpp.c
** File description:
** PauseMenu.cpp.c
*/

#include "PauseMenu.hpp"

PauseMenu::PauseMenu(Core *core)
{
    this->core = core;
    loadTextures();
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::loadTextures()
{
    Image back = LoadImage("resources/background_two.png");
    Image _playButton = LoadImage("resources/buttons/playButton.png");
    Image _optionsButton = LoadImage("resources/buttons/optionsButton.png");
    Image _exitButton = LoadImage("resources/buttons/exitButton.png");

    ImageResize(&back, WIDTH + 100, HEIGHT + 100);
    ImageResize(&_playButton, 200, 125);
    ImageResize(&_optionsButton, 200, 125);
    ImageResize(&_exitButton, 200, 125);

    background = LoadTextureFromImage(back);
    playButton = LoadTextureFromImage(_playButton);
    optionsButton = LoadTextureFromImage(_optionsButton);
    exitButton = LoadTextureFromImage(_exitButton);
}

Menu PauseMenu::menu()
{
    ClearBackground(WHITE);

    core->getSound().playMusic("hp");
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus().notify();

    mousePoint = GetMousePosition();

    initInfo();
    playMouseCheck();
    optionsMouseCheck();
    exitMouseCheck();
    drawings();

    if (exitAction) {
        exitAction = false;
        return EXIT;
    }
    if (playAction) {
        playAction = false;
        return GAME;
    }
    if (optionsAction) {
        optionsAction = false;
        return SETTINGS;
    }
    return PAUSE;
}

void PauseMenu::drawings()
{
    BeginDrawing();
    DrawTexture(background, -50, -50, WHITE);
    DrawTextureRec(playButton, playSourceRec,
                   Vector2{ playBtnBounds.x, playBtnBounds.y }, WHITE);
    DrawTextureRec(optionsButton, optionsSourceRec,
                   Vector2{ optionsBtnBounds.x, optionsBtnBounds.y }, WHITE);
    DrawTextureRec(exitButton, exitSourceRec,
                   Vector2{ exitBtnBounds.x, exitBtnBounds.y }, WHITE);
    EndDrawing();
}

void PauseMenu::initInfo()
{
    // Define frame rectangle for drawing
    playFrameHeight = (float)playButton.height/NUM_FRAMES;
    optionsFrameHeight = (float)optionsButton.height/NUM_FRAMES;
    exitFrameHeight = (float)exitButton.height/NUM_FRAMES;

    playSourceRec = {0, 0, (float)playButton.width, playFrameHeight};
    optionsSourceRec = {0, 0, (float)optionsButton.width, optionsFrameHeight};
    exitSourceRec = {0, 0, (float)exitButton.width, exitFrameHeight};

    // Define button bounds on screen
    playBtnBounds = {WIDTH/2.0f - playButton.width/2.0f,
                     HEIGHT/2.0f - playButton.height/NUM_FRAMES/2.0f - 150,
                     (float)playButton.width, playFrameHeight};
    optionsBtnBounds = {WIDTH/2.0f - optionsButton.width/2.0f,
                        HEIGHT/2.0f - optionsButton.height/NUM_FRAMES/2.0f,(float)optionsButton.width, optionsFrameHeight};
    exitBtnBounds = {WIDTH/2.0f - exitButton.width/2.0f,
                     HEIGHT/2.0f - exitButton.height/NUM_FRAMES/2.0f + 150,
                     (float)exitButton.width, exitFrameHeight};
}

void PauseMenu::playMouseCheck()
{
    // Check button state
    if (CheckCollisionPointRec(mousePoint, playBtnBounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            playState = 2;
        else
            playState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            playAction = true;
    }
    else playState = 0;

    if (playAction)
        core->getSound().playSound("button");
    playSourceRec.y = playState * playFrameHeight;
}

void PauseMenu::optionsMouseCheck()
{
    // Check button state
    if (CheckCollisionPointRec(mousePoint, optionsBtnBounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            optionsState = 2;
        else
            optionsState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            optionsAction = true;
    }
    else optionsState = 0;

    if (optionsAction)
        core->getSound().playSound("button");
    optionsSourceRec.y = optionsState * optionsFrameHeight;
}

void PauseMenu::exitMouseCheck()
{
    // Check button state
    if (CheckCollisionPointRec(mousePoint, exitBtnBounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            exitState = 2;
        else
            exitState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            exitAction = true;
    }
    else exitState = 0;

    if (exitAction)
        core->getSound().playSound("button");
    exitSourceRec.y = exitState * exitFrameHeight;
}
