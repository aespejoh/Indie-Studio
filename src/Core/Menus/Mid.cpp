/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Mid
*/

#include "Menus/Mid.hpp"

Mid::Mid(Core *core)
{
    this->core = core;
    try {
        checkFiles();
        loadModels();
        loadTextures();
    } catch (MainException exception) {
        std::cout << "Loop Error: " << exception.what();
        exit(84);
    }
    setPositions();
}

Mid::~Mid()
{
}

void Mid::checkFiles()
{
    std::ifstream bom_blue;
    bom_blue.open("resources/bomberman/blue_body.png");

    std::ifstream bom_black;
    bom_black.open("resources/bomberman/black_body.png");

    std::ifstream bom_yellow;
    bom_yellow.open("resources/bomberman/yellow_body.png");

    std::ifstream bom_red;
    bom_red.open("resources/bomberman/red_body.png");

    std::ifstream arrow_left_;
    arrow_left_.open("resources/arrow_left.png");

    std::ifstream arrow_right_;
    arrow_right_.open("resources/arrow_right.png");

    std::ifstream background_;
    background_.open("resources/background_two.png");

    std::ifstream font_;
    font_.open("resources/font/Caramel Sweets.ttf");

    std::ifstream model;
    model.open("resources/bomberman/Bomberman.obj");

    if (!bom_blue.is_open() || !bom_black.is_open() || !bom_red.is_open() ||
    !bom_yellow.is_open() || !arrow_left_.is_open() || !background_.is_open() ||
    !arrow_right_.is_open() || !model.is_open())
        throw MainException("Resource not found.");
}

Menu Mid::menu()
{
    ClearBackground(WHITE);

    if (core == nullptr)
        exit(84);
    core->getSound().playMusic("hp");
    core->getCameraHandler().setTarget(0.0f, 0.0f, -2.5f);
    core->getCameraHandler().setPosition(0.0f, 7.5f, 12.5f);
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus()->notify();
    mousePoint = GetMousePosition();

    initInfo();
    playMouseCheck();
    drawings();

    if (!arrow)
        core->setSecPlayer(true);

    if (playAction) {
        core->setPrevStatus(MID);
        playAction = false;
        return GAME;
    }
    return MID;
}

void Mid::loadModels()
{
    boomberman_blue = LoadModel("resources/bomberman/Bomberman.obj");
    boomberman_black = LoadModel("resources/bomberman/Bomberman.obj");
    boomberman_yellow = LoadModel("resources/bomberman/Bomberman.obj");
    boomberman_red = LoadModel("resources/bomberman/Bomberman.obj");

    blue = LoadTexture("resources/bomberman/blue_body.png");
    black = LoadTexture("resources/bomberman/black_body.png");
    yellow = LoadTexture("resources/bomberman/yellow_body.png");
    red = LoadTexture("resources/bomberman/red_body.png");

    if (blue.height == 0 || black.height == 0 || yellow.height == 0 || red.height == 0)
        throw MainException("Loading of textures in main menu failed.");

    boomberman_blue.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = blue;
    boomberman_black.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = black;
    boomberman_yellow.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = yellow;
    boomberman_red.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = red;
}

void Mid::drawings()
{
    BeginDrawing();
    drawButton();
    drawPlayersInfo();
    drawModels();
    EndDrawing();
}

void Mid::setPositions()
{
    position = { -1.5f, 0.0f, 0.0f };
    position_two = { -5.0f, 0.0f, 0.0f };
    position_three = { 2.0f, 0.0f, 0.0f };
    position_four = { 5.0f, 0.0f, 0.0f };
}

void Mid::loadTextures()
{
    Image _playButton = LoadImage("resources/buttons/playButton.png");
    Image _background = LoadImage("resources/background_two.png");

    if (_playButton.height == 0 || _background.height == 0)
        throw MainException("Loading of textures in main menu failed.");

    ImageResize(&_playButton, 200, 125);
    ImageResize(&_background, WIDTH + 100, HEIGHT + 100);

    playButton = LoadTextureFromImage(_playButton);
    background = LoadTextureFromImage(_background);

    font = LoadFont("resources/font/Caramel Sweets.ttf");
}

void Mid::drawModels()
{
    core->getCameraHandler().Begin3DMode();
    DrawModel(boomberman_blue, position, 0.075f, WHITE);
    DrawModel(boomberman_black, position_two, 0.075f, WHITE);
    DrawModel(boomberman_yellow, position_three, 0.075f, WHITE);
    DrawModel(boomberman_red, position_four, 0.075f, WHITE);
    core->getCameraHandler().End3DMode();
}

void Mid::drawPlayersInfo()
{
    DrawTextEx(font, "Pl 1", Vector2{130.0f, 190.0f}, 35, 2, BLACK);
    DrawTextEx(font, "Pl 2", Vector2{355.0f, 190.0f}, 35, 2, BLACK);
    DrawTextEx(font, "IA", Vector2{600.0f, 190.0f}, 35, 2, BLACK);
    DrawTextEx(font, "IA", Vector2{825.0f, 190.0f}, 35, 2, BLACK);
}

void Mid::drawButton()
{
    DrawTexture(background, -50, -50, WHITE);
    DrawTextureRec(playButton, playSourceRec,
                   Vector2{ playBtnBounds.x, playBtnBounds.y }, WHITE);
}

void Mid::playMouseCheck()
{
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

void Mid::initInfo()
{
    playFrameHeight = (float)playButton.height/NUM_FRAMES;

    playSourceRec = {0, 0, (float)playButton.width, playFrameHeight};

    playBtnBounds = {WIDTH/2.0f - playButton.width/2.0f,
                     HEIGHT/2.0f - playButton.height/NUM_FRAMES/2.0f + 250,
                     (float)playButton.width, playFrameHeight};
}
