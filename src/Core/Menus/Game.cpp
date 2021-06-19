/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Game
*/

#include "Menus/Game.hpp"

#include <utility>

Game::Game(Core *core) : _core(core)
{
    Player *player1 = new Player(1);
    _core->getLogic()._player1 = player1;
    Player *player2 = new Player(2);
    _core->getLogic()._player2 = player2;
    _core->getLogic().getBombModel()->load_model_texture();
    Image image = LoadImage("resources/cubicmap.png");
    _texture = LoadTextureFromImage(image);
    Mesh mesh = GenMeshCubicmap(image, Vector3{1.0f, 1.0f, 1.0f});
    _model = LoadModelFromMesh(mesh);
    Texture2D texture2 = LoadTexture("resources/cubicmap_atlas.png");
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture2;

    UnloadImage(image);
}

Game::~Game()
{

}

Menu Game::menu() {
    ClearBackground(WHITE);
    _core->getCameraHandler().setTarget(0.0f, 1.5f, 0.0f);

    BeginDrawing();
    _core->getCameraHandler().Begin3DMode();

    DrawModel(_model, mapPosition, 1.0f, WHITE);
    _core->getCameraHandler().End3DMode();
    DrawTextureEx(_texture, Vector2{ 1000 - _texture.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(1000 - _texture.width*4 - 20, 20, _texture.width*4, _texture.height*4, GREEN);
    _core->getLogic()._player1->draw();
    _core->getLogic()._player2->draw();
    for (const auto &item : _core->getLogic().getBombs())
        if (item != nullptr)
            item->draw();
    _core->getLogic().update();
    _core->getHandler().update();
    _core->getBus()->notify();
    _core->getCameraHandler().End3DMode();
    EndDrawing();

    return GAME;
}

