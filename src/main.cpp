/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Created by aespejo,
*/

#include "scene.hpp"
#include "InputModule/inputHandler.hpp"
#include "gameLogic.hpp"

int openRaylib()
{
    const int width = 800;
    const int height = 450;
    InitWindow(width, height, "\0");
    SetTargetFPS(60);
    MessageBus bus;
    InputHandler handler(&bus);
    GameLogic logic(&bus);
//    Scene main_scene;
//    Vector3 cam_pos = { 0.0f, 10.0f, 10.0f };
//    main_scene.setCameraPosition(cam_pos);
//    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    while (!WindowShouldClose())
    {
        logic.update();
        handler.update();
        bus.notify();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
/*
        BeginMode3D(main_scene.getCamera());
        DrawCube(cubePosition, 2, 2, 2, RED);
        DrawCubeWires(cubePosition, 2, 2, 2, MAROON);
        DrawGrid(10, 1);
        DrawFPS(10, 10);
        EndMode3D();
*/
    }
    CloseWindow();
    return 0;
}

int main()
{
    openRaylib();
}