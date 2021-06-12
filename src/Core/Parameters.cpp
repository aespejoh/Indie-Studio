/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Parameters
*/

#include "Parameters.hpp"

Parameters::Parameters(CameraHandler cameraHandler, InputHandler handler,
                       GameLogic logic, SoundHandler sound)
        : cameraHandler(cameraHandler), handler(handler), logic(logic),
          sound(sound) {
}

Parameters::~Parameters()
{
}

MessageBus &Parameters::getBus(){
    return bus;
}

void Parameters::setBus(const MessageBus &bus) {
    Parameters::bus = bus;
}

SoundHandler &Parameters::getSound(){
    return sound;
}

void Parameters::setSound(const SoundHandler &sound) {
    Parameters::sound = sound;
}

InputHandler &Parameters::getHandler(){
    return handler;
}


void Parameters::setHandler(const InputHandler &handler) {
    Parameters::handler = handler;
}

GameLogic &Parameters::getLogic(){
    return logic;
}

void Parameters::setLogic(const GameLogic &logic) {
    Parameters::logic = logic;
}

CameraHandler &Parameters::getCameraHandler(){
    return cameraHandler;
}

void Parameters::setCameraHandler(const CameraHandler &cameraHandler) {
    Parameters::cameraHandler = cameraHandler;
}
