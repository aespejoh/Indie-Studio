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
#include "raylib.h"

#define FPS 60
#define WIDTH 800
#define HEIGHT 450

class Core {
    public:
        Core();
        ~Core();
        void gameLoop();
        void loadMusicAndSounds();
        void setCamera();

    private:
        MessageBus bus;
        SoundHandler sound;
        InputHandler handler;
        GameLogic logic;
        CameraHandler cameraHandler;
        enum Menu {
                MAIN = 0,
                MID,
                GAME,
                GAME_OVER,
                EXIT,
                SETTINGS
            };
        Menu status;
};

#endif /* !CORE_HPP_ */
