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
        : sound(&bus), handler(&bus), logic(&bus), cameraHandler(&bus) {
    MapModule mapObject;
    _map = mapObject.generateMap();
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
    cameraHandler.setPosition(0.0f, 10.0f, 10.0f);
    cameraHandler.setTarget(0.0f, 0.0f, 0.0f);
    cameraHandler.setUp(0.0f, 1.0f, 0.0f);
    cameraHandler.setFov(45.0f);
    cameraHandler.setProjection(CAMERA_PERSPECTIVE);
}

void Core::gameLoop()
{
    MainMenu mainMenu(this);
    Mid midMenu(this);
    Game game(this);
    while (status != EXIT) {
        switch (status) {
            case MAIN:
                status = game.menu();
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
        if (WindowShouldClose())
            status = EXIT;
    }
    CloseAudioDevice();
    CloseWindow();
}


MessageBus Core::getBus() {
    return bus;
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

const std::vector<std::vector<int>> &Core::getMap() const {
    return _map;
}

int Core::getFps(){
    return fps;
}

void Core::setFps(int fps) {
    Core::fps = fps;
}

float Core::getMusicVolume(){
    return music_volume;
}

void Core::setMusicVolume(float musicVolume) {
    music_volume = musicVolume;
}
