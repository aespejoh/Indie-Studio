/*
** EPITECH PROJECT, 2021
** Victory.cpp.c
** File description:
** Victory.cpp.c
*/

#include "Victory.hpp"

Victory::Victory(Core *core)
{
    this->core = core;
    font = LoadFont("resources/font/Caramel Sweets.ttf");
    try {
        loadTextures();
    } catch (MainException exception) {
        std::cout << "Loop Error: " << exception.what();
        exit(84);
    }
}

Victory::~Victory()
{
}

void Victory::loadTextures()
{
    Image _exitButton = LoadImage("resources/buttons/exitButton.png");

    if (_exitButton.height == 0)
        throw MainException("Loading of textures in main menu failed.");

    ImageResize(&_exitButton, 200, 125);

    exitButton = LoadTextureFromImage(_exitButton);
}

Menu Victory::menu()
{
    ClearBackground(SKYBLUE);

    core->getSound().playMusic("hp");
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus()->notify();

    mousePoint = GetMousePosition();

    initInfo();
    exitMouseCheck();

    BeginDrawing();
    DrawTextEx(font, "YOU HAVE WON!", Vector2{(float)WIDTH/2 - 250, (float)
                                                                        HEIGHT/2 - 100},100, 2, WHITE);
    DrawTextureRec(exitButton, exitSourceRec,
                   Vector2{ exitBtnBounds.x, exitBtnBounds.y }, WHITE);
    EndDrawing();

    if (exitAction) {
        core->setPrevStatus(GAME_OVER);
        exitAction = false;
        return EXIT;
    }
    return VICTORY;
}

void Victory::initInfo()
{
    // Define frame rectangle for drawing
    exitFrameHeight = (float)exitButton.height/NUM_FRAMES;

    exitSourceRec = {0, 0, (float)exitButton.width, exitFrameHeight};

    exitBtnBounds = {WIDTH/2.0f - exitButton.width/2.0f,
                     HEIGHT/2.0f - exitButton.height/NUM_FRAMES/2.0f + 200,
                     (float)exitButton.width, exitFrameHeight};
}

void Victory::exitMouseCheck()
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
