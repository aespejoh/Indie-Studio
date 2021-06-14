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
    //core->getSound().playMusic("hp");
    core->getCameraHandler().setTarget(0.0f, 1.5f, 0.0f);
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
}

void Mid::drawings()
{
    BeginDrawing();
    core->getCameraHandler().Begin3DMode();
    DrawModel(boomberman_blue, position, 0.075f, WHITE);
    DrawModel(boomberman_black, position_two, 0.075f, WHITE);
    DrawModel(boomberman_yellow, position_three, 0.075f, WHITE);
    DrawModel(boomberman_red, position_four, 0.075f, WHITE);
    //DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
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
