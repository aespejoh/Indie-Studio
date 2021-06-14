/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Mid
*/

#include "Menus/Mid.hpp"

Mid::Mid(const Parameters &parameters) : parameters(parameters)
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
    parameters.getSound().playMusic("hp");
    parameters.getLogic().update();
    parameters.getSound().update();
    parameters.getHandler().update();
    parameters.getBus().notify();
    BeginDrawing();
    parameters.getCameraHandler().Begin3DMode();
    DrawModel(model, position, 0.05f, WHITE);
    DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
    parameters.getCameraHandler().End3DMode();
    EndDrawing();
    return MID;
}

void Mid::setBus(const MessageBus &bus)
{
    parameters.setBus(bus);
}