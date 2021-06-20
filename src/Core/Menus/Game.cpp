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
    Player *player1 = new Player(1, &_core->getMap());
    _core->getLogic()._player1 = player1;
    Player *player2 = new Player(2, &_core->getMap());
    _core->getLogic()._player2 = player2;
    AI *player3 = new AI(3, &_core->getMap(), _core->getBus());
    _core->getLogic()._player3 = player3;
    AI *player4 = new AI(4, &_core->getMap(), _core->getBus());
    _core->getLogic()._player4 = player4;
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
    _core->getCameraHandler().setPosition(13.0f, 25.0f, 19.0f);
    _core->getCameraHandler().setTarget(5.0f, -14.0f, 0.0f);
    ClearBackground(WHITE);
    BeginDrawing();
    _core->getCameraHandler().Begin3DMode();
    _core->getLogic().loadMap(&_core->getMap());
    if (_core->getLogic()._player1 != nullptr)
        _core->getLogic()._player1->draw();
    if (_core->getLogic()._player2 != nullptr)
        _core->getLogic()._player2->draw();
    if (_core->getLogic()._player3 != nullptr)
            _core->getLogic()._player3->draw();
    if (_core->getLogic()._player4 != nullptr)
            _core->getLogic()._player4->draw();
    _core->getRender().renderMap(_core->getMap());
    for (const auto &item : _core->getLogic().getBombs())
        if (item != nullptr)
            item->draw();
    _core->getCameraHandler().End3DMode();
    DrawTextureEx(_texture, Vector2{ 1000 - _texture.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
    DrawRectangleLines(1000 - _texture.width*4 - 20, 20, _texture.width*4, _texture.height*4, GREEN);
    _core->getLogic().updateAI();
    _core->getLogic().update();
    _core->getHandler().update();
    _core->getBus()->notify();
    _core->getCameraHandler().End3DMode();
    EndDrawing();
    return is_gameover();
}

Menu Game::is_gameover()
{
    if (_core->isSecPlayer()) {
        if (_core->getLogic()._player3 == nullptr && _core->getLogic()._player4 ==
            nullptr && (_core->getLogic()._player1 == nullptr || _core->getLogic()._player2 ==
            nullptr))
            return VICTORY;
        if (_core->getLogic()._player1 == nullptr && _core->getLogic()._player2 ==
            nullptr)
            return GAME_OVER;
    } else {
        if (_core->getLogic()._player1 == nullptr)
            return GAME_OVER;
        if (_core->getLogic()._player2 == nullptr && _core->getLogic()._player3 ==
            nullptr && _core->getLogic()._player4 == nullptr)
            return VICTORY;
    }
    return GAME;
}


