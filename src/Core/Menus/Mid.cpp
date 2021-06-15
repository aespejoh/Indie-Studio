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
    loadTexture();
}

Mid::~Mid()
{
}

Menu Mid::menu()
{
    ClearBackground(WHITE);
    setPositions();
    BoundingBox bounds = GetMeshBoundingBox(boomberman_blue.meshes[0]);  // Set model
    // bounds
    if (core == nullptr)
        exit(84);
    core->getSound().playMusic("hp2");
    core->getCameraHandler().setTarget(0.0f, 0.0f, -2.5f);
    core->getCameraHandler().setPosition(0.0f, 7.5f, 12.5f);
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus().notify();
    drawings();
    return MID;
}

void Mid::loadTexture()
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

    Image left = LoadImage("resources/arrow_left.png");
    ImageResize(&left, 50, 50);

    arrow_left = LoadTextureFromImage(left);

    Image right = LoadImage("resources/arrow_right.png");
    ImageResize(&right, 50, 50);

    arrow_right = LoadTextureFromImage(right);

    font = LoadFont("resources/font/BOMBERMA.TTF");
}

void Mid::drawings()
{
    BeginDrawing();
    DrawTexture(arrow_left, 75, 180, WHITE);
    DrawTextEx(font, "Test", Vector2{120.0f, 190.0f}, 35, 2, BLACK);
    DrawTexture(arrow_right, 225, 180, WHITE);
    DrawTexture(arrow_left, 300, 180, WHITE);
    DrawTexture(arrow_right, 450, 180, WHITE);
    DrawTexture(arrow_left, 525, 180, WHITE);
    DrawTexture(arrow_right, 675, 180, WHITE);
    DrawTexture(arrow_left, 750, 180, WHITE);
    DrawTextEx(font, "IA", Vector2{795.0f, 190.0f}, 35, 2, BLACK);
    DrawTexture(arrow_right, 900, 180, WHITE);
    core->getCameraHandler().Begin3DMode();
    DrawModel(boomberman_blue, position, 0.075f, WHITE);
    DrawModel(boomberman_black, position_two, 0.075f, WHITE);
    DrawModel(boomberman_yellow, position_three, 0.075f, WHITE);
    DrawModel(boomberman_red, position_four, 0.075f, WHITE);
    core->getCameraHandler().End3DMode();
    EndDrawing();
}

void Mid::setPositions()
{
    position = { -1.5f, 0.0f, 0.0f };             // Set model position
    position_two = { -5.0f, 0.0f, 0.0f };
    position_three = { 2.0f, 0.0f, 0.0f };
    position_four = { 5.0f, 0.0f, 0.0f };
}
