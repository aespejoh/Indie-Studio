/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Core
*/

#include <MapModule/mapModule.h>
#include <MainExceptions.hpp>
#include "Menus/MainMenu.hpp"
#include "Menus/Mid.hpp"
#include "Menus/Game.hpp"
#include "Menus/Settings.hpp"
#include "Menus/PauseMenu.hpp"
#include "Menus/GameOver.hpp"
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
    try {
        sound.addMusic("hp2", "resources/hp2.mp3");
        sound.addMusic("hp", "resources/hp.mp3");
        sound.addSound("button", "resources/buttons/button.mp3");
        sound.setMusicVolume("hp", music_volume);
    } catch (MainException exception) {
        std::cout << "Error: " << exception.what();
        exit(84);
    }
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
    MainMenu mainMenu(this);
    Mid midMenu(this);
    Game game(this);
    Settings settings(this);
    PauseMenu pause(this);
    GameOver gameOver(this);
    renderModule.loadTextures();
    while (status != EXIT) {
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
            case SETTINGS:
                status = settings.menu();
                break;
            case PAUSE:
                status = pause.menu();
                break;
            default:
                status = mainMenu.menu();
                break;
        }
        if (IsKeyReleased(KEY_P) && status != MAIN && status != SETTINGS)
            status = PAUSE;
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

bool Core::isSecPlayer() const
{
    return sec_player;
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
