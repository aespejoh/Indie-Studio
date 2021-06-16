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
    Player *player1 = new Player(0);
    player1->load_model_and_texture(1);
    _core->getLogic()._player1 = player1;
    Player *player2 = new Player(1);
    player2->load_model_and_texture(2);
    _core->getLogic()._player2 = player2;
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
    ClearBackground(WHITE);
    _core->getCameraHandler().setTarget(0.0f, 1.5f, 0.0f);
    BeginDrawing();
    _core->getCameraHandler().Begin3DMode();
    DrawGrid(10, 1);
    _core->getLogic()._player1->draw();
    _core->getLogic()._player2->draw();
    _core->getLogic().update();
    _core->getHandler().update();
    _core->getBus()->notify();
    _core->getCameraHandler().End3DMode();
    EndDrawing();
    return GAME;
}
