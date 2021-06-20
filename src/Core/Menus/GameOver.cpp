/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** GameOver
*/

#include "Menus/GameOver.hpp"

GameOver::GameOver(Core *core)
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

GameOver::~GameOver()
{
}

void GameOver::loadTextures()
{
    Image _playButton = LoadImage("resources/buttons/playButton.png");

    if (_playButton.height == 0)
        throw MainException("Loading of textures in main menu failed.");

    ImageResize(&_playButton, 200, 125);

    playButton = LoadTextureFromImage(_playButton);
}

Menu GameOver::menu()
{
    ClearBackground(BLACK);

    core->getSound().playMusic("hp");
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus().notify();

    mousePoint = GetMousePosition();

    initInfo();
    playMouseCheck();

    BeginDrawing();
    DrawTextEx(font, "GAME OVER", Vector2{(float)WIDTH/2 - 200, (float)
    HEIGHT/2 - 100},100, 2, RED);
    DrawTextureRec(playButton, playSourceRec,
                   Vector2{ playBtnBounds.x, playBtnBounds.y }, WHITE);
    EndDrawing();

    if (playAction) {
        core->setPrevStatus(GAME_OVER);
        playAction = false;
        return MID;
    }
    return GAME_OVER;
}

void GameOver::initInfo()
{
    // Define frame rectangle for drawing
    playFrameHeight = (float)playButton.height/NUM_FRAMES;

    playSourceRec = {0, 0, (float)playButton.width, playFrameHeight};

    playBtnBounds = {WIDTH/2.0f - playButton.width/2.0f,
                     HEIGHT/2.0f - playButton.height/NUM_FRAMES/2.0f + 200,
                     (float)playButton.width, playFrameHeight};
}

void GameOver::playMouseCheck()
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