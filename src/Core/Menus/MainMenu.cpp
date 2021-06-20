/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** MainMenu
*/

#include "Menus/MainMenu.hpp"

MainMenu::MainMenu(Core *core)
{
    this->core = core;
    try {
        checkFiles();
        loadTextures();
    } catch (MainException exception) {
        std::cout << "Loop Error: " << exception.what();
        exit(84);
    }
}

MainMenu::~MainMenu()
{
}

void MainMenu::checkFiles()
{
    std::ifstream background_;
    background_.open("resources/background.png");

    std::ifstream playButton_;
    playButton_.open("resources/buttons/playButton.png");

    std::ifstream optionsButton_;
    optionsButton_.open("resources/buttons/optionsButton.png");

    std::ifstream exitButton_;
    exitButton_.open("resources/buttons/exitButton.png");

    if (!background_.is_open() || !playButton_.is_open() || !optionsButton_.is_open() || !exitButton_.is_open())
        throw MainException("Resource not found.");
}

void MainMenu::loadTextures()
{
    Image back = LoadImage("resources/background.png");
    Image _playButton = LoadImage("resources/buttons/playButton.png");
    Image _optionsButton = LoadImage("resources/buttons/optionsButton.png");
    Image _exitButton = LoadImage("resources/buttons/exitButton.png");

    if (back.height == 0 || _playButton.height == 0 ||
        _optionsButton.height == 0 || _exitButton.height == 0)
        throw MainException("Loading of textures in main menu failed.");

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
    ClearBackground(WHITE);

    core->getSound().playMusic("hp");
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus()->notify();

    mousePoint = GetMousePosition();

    initInfo();
    playMouseCheck();
    optionsMouseCheck();
    exitMouseCheck();
    drawings();

    if (exitAction) {
        core->setPrevStatus(MAIN);
        exitAction = false;
        return EXIT;
    }
    if (playAction) {
        core->setPrevStatus(MAIN);
        playAction = false;
        return MID;
    }
    if (optionsAction) {
        core->setPrevStatus(MAIN);
        optionsAction = false;
        return SETTINGS;
    }
    return MAIN;
}

void MainMenu::drawings()
{
    BeginDrawing();
    DrawTexture(background, 0, 0, WHITE);
    DrawTextureRec(playButton, playSourceRec,
                   Vector2{ playBtnBounds.x, playBtnBounds.y }, WHITE);
    DrawTextureRec(optionsButton, optionsSourceRec,
                   Vector2{ optionsBtnBounds.x, optionsBtnBounds.y }, WHITE);
    DrawTextureRec(exitButton, exitSourceRec,
                   Vector2{ exitBtnBounds.x, exitBtnBounds.y }, WHITE);
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

    if (playAction)
        core->getSound().playSound("button");
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

    if (optionsAction)
       core->getSound().playSound("button");
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

    if (exitAction)
        core->getSound().playSound("button");
    exitSourceRec.y = exitState * exitFrameHeight;
}
