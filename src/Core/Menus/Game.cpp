/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Game
*/

#include "Menus/Game.hpp"

Game::Game(Core *core)
{
    _core = core;
}

Game::~Game()
{

}

Menu Game::menu() {
    Vector3 mapPosition = { -16.0f, 0.0f, -8.0f };
    Image image = LoadImage("resources/cubicmap.png");
    Texture2D texture = LoadTextureFromImage(image);

    Mesh mesh = GenMeshCubicmap(image, Vector3{1.0f, 1.0f, 1.0f});
    Model model = LoadModelFromMesh(mesh);

    Texture2D texture2 = LoadTexture("resources/cubicmap_atlas.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture2;

    UnloadImage(image);

    BeginDrawing();
    _core->getCameraHandler().Begin3DMode();

    DrawModel(model, mapPosition, 1.0f, WHITE);

    _core->getCameraHandler().End3DMode();

    DrawTextureEx(texture, (Vector2){ 1000 - texture.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(1000 - texture.width*4 - 20, 20, texture.width*4, texture.height*4, GREEN);

    return GAME;
}