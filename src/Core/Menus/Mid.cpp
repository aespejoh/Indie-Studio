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
    loadModels();
    loadTextures();
    loadRect();
    setPositions();
}

Mid::~Mid()
{
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
    core->getBus().notify();
    mousePoint = GetMousePosition();

    initInfo();
    checkMouse();
    playMouseCheck();
    drawings();

    if (!arrow)
        core->setSecPlayer(true);

    if (playAction)
        return MID; //tmp
    return MID;
}

void Mid::loadModels()
{
    boomberman_blue = LoadModel("resources/bomberman/Bomberman.obj");
    blue = LoadTexture("resources/bomberman/blue_body.png");
    boomberman_blue.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = blue;

    boomberman_black = LoadModel("resources/bomberman/Bomberman.obj");
    black = LoadTexture("resources/bomberman/black_body.png");
    boomberman_black.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = black;

    boomberman_yellow = LoadModel("resources/bomberman/Bomberman.obj");
    yellow = LoadTexture("resources/bomberman/yellow_body.png");
    boomberman_yellow.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = yellow;

    boomberman_red = LoadModel("resources/bomberman/Bomberman.obj");
    red = LoadTexture("resources/bomberman/red_body.png");
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
    Image left = LoadImage("resources/arrow_left.png");
    ImageResize(&left, 50, 50);
    arrow_left = LoadTextureFromImage(left);

    Image right = LoadImage("resources/arrow_right.png");
    ImageResize(&right, 50, 50);
    arrow_right = LoadTextureFromImage(right);

    Image _playButton = LoadImage("resources/buttons/playButton.png");
    ImageResize(&_playButton, 200, 125);
    playButton = LoadTextureFromImage(_playButton);

    Image _background = LoadImage("resources/background_two.png");
    ImageResize(&_background, WIDTH + 100, HEIGHT + 100);
    background = LoadTextureFromImage(_background);

    font = LoadFont("resources/font/Caramel Sweets.ttf");
}

void Mid::loadRect()
{
    arrow_left_rect = {300, 180, (float)arrow_left.width,
                           (float)arrow_left.height};
    arrow_right_rect = {450, 180, (float)arrow_left.width,
                            (float)arrow_left.height};
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
    DrawTexture(arrow_left, 300, 180, WHITE);
    if (arrow)
        DrawTextEx(font, "IA", Vector2{375.0f, 190.0f}, 35, 2, BLACK);
    else
        DrawTextEx(font, "Pl 2", Vector2{355.0f, 190.0f}, 35, 2, BLACK);
    DrawTexture(arrow_right, 450, 180, WHITE);
    DrawTextEx(font, "IA", Vector2{600.0f, 190.0f}, 35, 2, BLACK);
    DrawTextEx(font, "IA", Vector2{825.0f, 190.0f}, 35, 2, BLACK);
}

void Mid::checkMouse()
{
    if (CheckCollisionPointRec(mousePoint, arrow_left_rect) ||
        CheckCollisionPointRec(mousePoint, arrow_right_rect)) {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && arrow)
            arrow = false;
        else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !arrow)
            arrow = true;
    }
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
