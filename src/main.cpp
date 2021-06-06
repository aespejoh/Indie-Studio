/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Created by aespejo,
*/

#include <CameraModule/CameraHandler.hpp>
#include "inputHandler.hpp"
#include "Core/gameLogic.hpp"
#include "SoundModule/SoundHandler.hpp"

int openRaylib()
{
    const int width = 800;
    const int height = 450;
    InitWindow(width, height, "Testing Main");
    SetTargetFPS(60);
    MessageBus bus;
    InputHandler handler(&bus);
    GameLogic logic(&bus);
    SoundHandler sound(&bus);
    CameraHandler cameraHandler(&bus);

    cameraHandler.setPosition(0.0f, 10.0f, 10.0f);
    cameraHandler.setTarget(0.0f, 0.0f, 0.0f);
    cameraHandler.setUp(0.0f, 1.0f, 0.0f);
    cameraHandler.setFov(45.0f);
    cameraHandler.setProjection(CAMERA_PERSPECTIVE);
    sound.addMusic("hp2", "resources/hp2.mp3");
    sound.addMusic("hp", "resources/hp.mp3");
    sound.playMusic("hp2");

    while (!WindowShouldClose())
    {
        logic.update();
        sound.update();
        handler.update();
        bus.notify();
        BeginDrawing();
        cameraHandler.Begin3DMode();
        DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
        cameraHandler.End3DMode();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

int main()
{
    openRaylib();
}