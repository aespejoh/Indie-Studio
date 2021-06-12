/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Parameters
*/

#ifndef PARAMETERS_HPP_
#define PARAMETERS_HPP_

#include <CameraModule/CameraHandler.hpp>
#include <SoundModule/SoundHandler.hpp>
#include <gameLogic.hpp>
#include <inputHandler.hpp>
#include "raylib.h"

class Parameters {
    public:
        Parameters(CameraHandler cameraHandler, InputHandler handler,
                   GameLogic logic, SoundHandler sound);
        ~Parameters();
        MessageBus &getBus();
        void setBus(const MessageBus &bus);
        SoundHandler &getSound();
        void setSound(const SoundHandler &sound);
        InputHandler &getHandler();
        void setHandler(const InputHandler &handler);
        GameLogic &getLogic();
        void setLogic(const GameLogic &logic);
        CameraHandler &getCameraHandler();
        void setCameraHandler(const CameraHandler &cameraHandler);

    protected:
    private:
        MessageBus bus;
        SoundHandler sound;
        InputHandler handler;
        GameLogic logic;
        CameraHandler cameraHandler;
};

#endif /* !PARAMETERS_HPP_ */