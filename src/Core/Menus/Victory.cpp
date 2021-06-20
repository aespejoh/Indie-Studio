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
    Image _playButton = LoadImage("resources/buttons/playButton.png");

    if (_playButton.height == 0)
        throw MainException("Loading of textures in main menu failed.");

    ImageResize(&_playButton, 200, 125);

    playButton = LoadTextureFromImage(_playButton);
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
    playMouseCheck();

    BeginDrawing();
    DrawTextEx(font, "YOU HAVE WON!", Vector2{(float)WIDTH/2 - 250, (float)
                                                                        HEIGHT/2 - 100},100, 2, WHITE);
    DrawTextureRec(playButton, playSourceRec,
                   Vector2{ playBtnBounds.x, playBtnBounds.y }, WHITE);
    EndDrawing();

    if (playAction) {
        core->setPrevStatus(GAME_OVER);
        playAction = false;
        return MID;
    }
    return VICTORY;
}

void Victory::initInfo()
{
    // Define frame rectangle for drawing
    playFrameHeight = (float)playButton.height/NUM_FRAMES;

    playSourceRec = {0, 0, (float)playButton.width, playFrameHeight};

    playBtnBounds = {WIDTH/2.0f - playButton.width/2.0f,
                     HEIGHT/2.0f - playButton.height/NUM_FRAMES/2.0f + 200,
                     (float)playButton.width, playFrameHeight};
}

void Victory::playMouseCheck()
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
