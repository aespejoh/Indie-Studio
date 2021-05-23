/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Created by aespejo,
*/

#include "inputHandler.hpp"
#include "Core/gameLogic.hpp"

int openRaylib()
{
    const int width = 800;
    const int height = 450;
    InitWindow(width, height, "\0");
    SetTargetFPS(60);
    MessageBus bus;
    InputHandler handler(&bus);
    GameLogic logic(&bus);

    while (!WindowShouldClose())
    {
        logic.update();
        handler.update();
        bus.notify();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

int main()
{
    openRaylib();
}