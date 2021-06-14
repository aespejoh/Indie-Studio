/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Game
*/

#include "Menus/Game.hpp"

Game::Game(Core *core)  : _core(core)
{
    Object* player = _scene.CreateObject();
    RenderComponent* renderComponent = new RenderComponent(player);
    renderComponent->load_texture("resources/bomberman/body.png");
    renderComponent->load_model("resources/bomberman/Bomberman.obj");
    renderComponent->setScale(0.075f);
    player->loadComponent(renderComponent);
    core->getCameraHandler().setTarget(0.0f, 1.5f, 0.0f);
}

Game::~Game()
{
}

Menu Game::menu()
{
    ClearBackground(WHITE);
    BeginDrawing();
    auto objects = _scene.getObjects();
    for (const auto &item : objects) {
        item.second->draw();
    }
    EndDrawing();
    return GAME;
}
