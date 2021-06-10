/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Core
*/

#include "Core.hpp"

Core::Core() : sound(&bus), handler(&bus), logic(&bus), cameraHandler(&bus)
{
    InitWindow(WIDTH, HEIGHT, "\0");
    SetTargetFPS(FPS);
    loadMusicAndSounds();
    setCamera();
    status = MAIN;
    Game game(this);
}

Core::~Core()
{

}

void Core::loadMusicAndSounds() {
    sound.addMusic("hp2", "resources/hp2.mp3");
    sound.addMusic("hp", "resources/hp.mp3");
}

void Core::setCamera() {
    cameraHandler.setPosition(0.0f, 10.0f, 10.0f);
    cameraHandler.setTarget(0.0f, 0.0f, 0.0f);
    cameraHandler.setUp(0.0f, 1.0f, 0.0f);
    cameraHandler.setFov(45.0f);
    cameraHandler.setProjection(CAMERA_PERSPECTIVE);
}

void Core::gameLoop() {

    while (status != EXIT) {
        sound.playMusic("hp2");
        logic.update();
        sound.update();
        handler.update();
        bus.notify();
        BeginDrawing();
        cameraHandler.Begin3DMode();
        DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
        cameraHandler.End3DMode();
        EndDrawing();
        if (WindowShouldClose())
            status = EXIT;
    }
    CloseWindow();
}