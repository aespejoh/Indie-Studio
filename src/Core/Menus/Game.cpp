/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Game
*/

#include "Menus/Game.hpp"

Game::Game(Core *core)  : _core(core)
{
    Player *player1 = new Player(0);
    _players.push_back(player1);
    for (const auto &item : _players) {
        item->load_model_and_texture();
    }


/*
    Object* player = _scene.CreateObject();
    RenderComponent* renderComponent = new RenderComponent(player);
    renderComponent->load_texture("resources/bomberman/body.png");
    renderComponent->load_model("resources/bomberman/Bomberman.obj");
    renderComponent->setScale(0.075f);
    player->loadComponent(renderComponent);
    core->getCameraHandler().setTarget(0.0f, 1.5f, 0.0f);
*/
}

Game::~Game()
{
}

Menu Game::menu()
{
    Vector3 vector3 = {0.5f, 1.0f, 0.5f};
    Vector3 vector3_2 = {0.5f, 1.0f, 0.5f};
    Vector3 new_vector = vector3 + vector3_2;
    ClearBackground(WHITE);
    _core->getCameraHandler().setTarget(0.0f, 1.5f, 0.0f);
    BeginDrawing();
    _core->getCameraHandler().Begin3DMode();
    DrawGrid(10, 1);
    for (const auto &item : _players) {
        item->draw();
    }
    _core->getCameraHandler().End3DMode();
    EndDrawing();
    return GAME;
}
