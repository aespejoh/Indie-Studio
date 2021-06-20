/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** GameOver
*/

#include "Menus/GameOver.hpp"

GameOver::GameOver(Core *core)
{
    this->core = core;
    font = LoadFont("resources/font/Caramel Sweets.ttf");
}

GameOver::~GameOver()
{
}

Menu GameOver::menu()
{
    ClearBackground(BLACK);

    core->getSound().playMusic("hp");
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus()->notify();

    BeginDrawing();
    DrawTextEx(font, "GAME OVER", Vector2{(float)WIDTH/2 - 200, (float)
    HEIGHT/2 - 100},100, 2, RED);
    EndDrawing();
    return GAME_OVER;
}