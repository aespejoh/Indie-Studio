/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Mid
*/

#include "Menus/Mid.hpp"

Mid::Mid(Core *core)
{
}

Mid::~Mid()
{
}

Menu Mid::menu()
{
    ClearBackground(WHITE);
    Model model = LoadModel("resources/bomberman/Bomberman.obj");
    Texture2D texture = LoadTexture("resources/bomberman/blue_body.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    Vector3 position = { 0.0f, 0.0f, 0.0f };                // Set model position

    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);  // Set model
    // bounds
    //core->getSound().playMusic("hp");
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus().notify();
    BeginDrawing();
    core->getCameraHandler().Begin3DMode();
    DrawModel(model, position, 0.05f, WHITE);
    DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
    core->getCameraHandler().End3DMode();
    EndDrawing();
    return MID;
}