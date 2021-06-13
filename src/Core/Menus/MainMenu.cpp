/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** MainMenu
*/

#include "Menus/MainMenu.hpp"

MainMenu::MainMenu(const Parameters& parameters)
        : parameters(parameters) {
}

MainMenu::~MainMenu()
{
}

void MainMenu::loadTextures()
{
    Image back = LoadImage("resources/background.png");
    Image _playButton = LoadImage("resources/buttons/playButton.png");
    Image _optionsButton = LoadImage("resources/buttons/optionsButton.png");
    Image _exitButton = LoadImage("resources/buttons/exitButton.png");

    ImageResize(&back, WIDTH, HEIGHT);
    ImageResize(&_playButton, 200, 125);
    ImageResize(&_optionsButton, 200, 125);
    ImageResize(&_exitButton, 200, 125);

    background = LoadTextureFromImage(back);
    playButton = LoadTextureFromImage(_playButton);
    optionsButton = LoadTextureFromImage(_optionsButton);
    exitButton = LoadTextureFromImage(_exitButton);
}

Menu MainMenu::menu()
{
    loadTextures();
    parameters.getSound().playMusic("hp");
    parameters.getLogic().update();
    parameters.getSound().update();
    parameters.getHandler().update();
    parameters.getBus().notify();

    mousePoint = GetMousePosition();

    initInfo();
    playMouseCheck();
    optionsMouseCheck();
    exitMouseCheck();
    drawings();

    if (exitAction)
        return EXIT;
    return MAIN;
}

void MainMenu::setBus(const MessageBus &bus)
{
    parameters.setBus(bus);
}

void MainMenu::drawings()
{
    BeginDrawing();
    DrawTexture(background, 0, 0, WHITE);
    //DrawRectangle(100, 100, 120, 60, RED);
    DrawTextureRec(playButton, playSourceRec,
                   (Vector2){ playBtnBounds.x, playBtnBounds.y }, WHITE);
    DrawTextureRec(optionsButton, optionsSourceRec,
                   (Vector2){ optionsBtnBounds.x, optionsBtnBounds.y }, WHITE);
    DrawTextureRec(exitButton, exitSourceRec,
                   (Vector2){ exitBtnBounds.x, exitBtnBounds.y }, WHITE);
    parameters.getCameraHandler().Begin3DMode();
    //DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
    parameters.getCameraHandler().End3DMode();
    EndDrawing();
}

void MainMenu::initInfo()
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
                 HEIGHT/2.0f - playButton.height/NUM_FRAMES/2.0f,
                 (float)playButton.width, playFrameHeight};
    optionsBtnBounds = {WIDTH/2.0f - optionsButton.width/2.0f,
                        HEIGHT/2.0f - optionsButton.height/NUM_FRAMES/2.0f +
                        75,(float)optionsButton.width, optionsFrameHeight};
    exitBtnBounds = {WIDTH/2.0f - exitButton.width/2.0f,
                     HEIGHT/2.0f - exitButton.height/NUM_FRAMES/2.0f + 150,
                     (float)exitButton.width, exitFrameHeight};
}

void MainMenu::playMouseCheck()
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

    //if (playAction)
    //    parameters.getSound().playSound("button");
    playSourceRec.y = playState * playFrameHeight;
}

void MainMenu::optionsMouseCheck()
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

    //if (playAction)
    //    parameters.getSound().playSound("button");
    optionsSourceRec.y = optionsState * optionsFrameHeight;
}

void MainMenu::exitMouseCheck()
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

    //if (playAction)
    //    parameters.getSound().playSound("button");
    exitSourceRec.y = exitState * exitFrameHeight;
}
