/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** MainMenu
*/

#include "Menus/MainMenu.hpp"

MainMenu::MainMenu(const Parameters& parameters)
        : parameters(parameters) {
}

MainMenu::~MainMenu()
{
}

void MainMenu::menu()
{
    parameters.getSound().playMusic("hp2");
    parameters.getLogic().update();
    parameters.getSound().update();
    parameters.getHandler().update();
    parameters.getBus().notify();
    BeginDrawing();
    parameters.getCameraHandler().Begin3DMode();
    DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
    parameters.getCameraHandler().End3DMode();
    EndDrawing();
}

Parameters &MainMenu::getParameters()
{
    return parameters;
}

void MainMenu::setParameters(const Parameters &parameters)
{
    MainMenu::parameters = parameters;
}

void MainMenu::setCameraHandler(const CameraHandler &cameraHandler)
{
    parameters.setCameraHandler(cameraHandler);
}

CameraHandler &MainMenu::getCameraHandler()
{
    return parameters.getCameraHandler();
}

void MainMenu::setLogic(const GameLogic &logic)
{
    parameters.setLogic(logic);
}

GameLogic &MainMenu::getLogic()
{
    return parameters.getLogic();
}

void MainMenu::setHandler(const InputHandler &handler)
{
    parameters.setHandler(handler);
}

InputHandler &MainMenu::getHandler()
{
    return parameters.getHandler();
}

void MainMenu::setSound(const SoundHandler &sound)
{
    parameters.setSound(sound);
}

SoundHandler &MainMenu::getSound()
{
    return parameters.getSound();
}

void MainMenu::setBus(const MessageBus &bus)
{
    parameters.setBus(bus);
}

MessageBus &MainMenu::getBus()
{
    return parameters.getBus();
}

