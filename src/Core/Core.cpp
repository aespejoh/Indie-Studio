/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Core
*/

#include <MapModule/mapModule.h>
#include "Menus/MainMenu.hpp"
#include "Menus/Mid.hpp"
#include "Menus/Game.hpp"
#include "Core.hpp"

Core::Core()
        : sound(&bus), handler(&bus), logic(&bus), cameraHandler(&bus), renderModule(&bus){
    map.generateMap();
    InitWindow(width, height, "\0");
    SetTargetFPS(fps);
    loadMusicAndSounds();
    setCamera();
    status = MAIN;
}

Core::~Core()
{

}

void Core::loadMusicAndSounds() {
    sound.addMusic("hp2", "resources/hp2.mp3");
    sound.addMusic("hp", "resources/hp.mp3");
    sound.addSound("button", "resources/buttons/button.mp3");
}

void Core::setCamera() {
    cameraHandler.setPosition(13.0f, 25.0f, 19.0f);
    cameraHandler.setTarget(5.0f, -14.0f, 0.0f);
    cameraHandler.setUp(0.0f, 1.0f, 0.0f);
    cameraHandler.setFov(45.0f);
    cameraHandler.setProjection(CAMERA_PERSPECTIVE);
}

void Core::gameLoop()
{
    //sound.playMusic("hp2");
    //sound.playSound("button");
    MainMenu mainMenu(this);
    Mid midMenu(this);
    Game game(this);
    //sound.playMusic("hp");
    sound.playMusic("hp");
    while (status != EXIT) {
        status = game.menu();
        /*
        switch (status) {
            case MAIN:
                status = mainMenu.menu();
                break;
            case GAME:
                status = game.menu();
                break;
            case MID:
                status = midMenu.menu();
                break;
            default:
                status = mainMenu.menu();
                break;
        }
        if (status == MAIN)
            status = mainMenu.menu();
        else if (status == MID)
            status = midMenu.menu();
        else
            status = mainMenu.menu();
        sound.playMusic("hp2");
        status = mainMenu.menu();
        _logic.update();
        sound.update();
        handler.update();
        bus.notify();
        BeginDrawing();
        cameraHandler.Begin3DMode();
        DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
        cameraHandler.End3DMode();
        EndDrawing();
        */
        if (WindowShouldClose())
            status = EXIT;
    }
    CloseAudioDevice();
    CloseWindow();
}


MessageBus * Core::getBus() {
    return &bus;
}

SoundHandler &Core::getSound() {
    return sound;
}

InputHandler &Core::getHandler() {
    return handler;
}

GameLogic &Core::getLogic() {
    return logic;
}

CameraHandler &Core::getCameraHandler() {
    return cameraHandler;
}

void Core::setSecPlayer(bool secPlayer)
{
    sec_player = secPlayer;
}

MapModule &Core::getMap()
{
    return (map);
}

RenderModule Core::getRender()
{
    return (renderModule);
}
