/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <CameraModule/CameraHandler.hpp>
#include <SoundModule/SoundHandler.hpp>
#include <gameLogic.hpp>
#include <inputHandler.hpp>
#include "Menus.hpp"
#include "raylib.h"

class Core {
    public:
        Core();
        ~Core();
        void gameLoop();
        void loadMusicAndSounds();
        void setCamera();
        MessageBus getBus();
        SoundHandler &getSound();
        InputHandler &getHandler();
        GameLogic &getLogic();
        CameraHandler &getCameraHandler();

    private:
        MessageBus bus;
        SoundHandler sound;
        InputHandler handler;
        GameLogic logic;
        CameraHandler cameraHandler;
        //MainMenu mainMenu;
        Menu status;
    private:
        int fps = 60;
        int width = 1000;
        int height = 750;

};

#endif /* !CORE_HPP_ */
