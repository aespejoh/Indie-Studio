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
#include "Menus/Game.hpp"
#include "raylib.h"
#include <Menus/MainMenu.hpp>

#define FPS 60
#define WIDTH 800
#define HEIGHT 450

enum Menu {
    MAIN = 0,
    MID,
    GAME,
    GAME_OVER,
    EXIT,
    SETTINGS
};

class Core {
    public:
        Core();
        ~Core();
        void gameLoop();
        void loadMusicAndSounds();
        void setCamera();
        const SoundHandler &getSound() const;

    private:
        MessageBus bus;
        SoundHandler sound;
        InputHandler handler;
        GameLogic logic;
        CameraHandler cameraHandler;
        Menu status;

    private:
        MainMenu mainMenu;
};

#endif /* !CORE_HPP_ */
