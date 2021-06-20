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
#include <Objects/renderModule.hpp>
#include "Menus.hpp"
#include "raylib.h"

class Core {
    public:
        Core();
        ~Core();
        void gameLoop();
        void loadMusicAndSounds();
        void setCamera();
        MessageBus* getBus();
        SoundHandler &getSound();
        InputHandler &getHandler();
        GameLogic &getLogic();
        CameraHandler &getCameraHandler();
        const std::vector<std::vector<int>> &getMap() const;
        void setSecPlayer(bool secPlayer);
        int getFps();
        void setFps(int fps);
        float getMusicVolume();
        void setMusicVolume(float musicVolume);
        MapModule &getMap();
        RenderModule getRender();
        bool isSecPlayer() const;
        void setPrevStatus(Menu prevStatus);
        Menu getPrevStatus() const;

private:
        MessageBus bus;
        SoundHandler sound;
        InputHandler handler;
        GameLogic logic;
        CameraHandler cameraHandler;
        MapModule map;
        RenderModule renderModule;
        Menu status;
        Menu prevStatus;
        bool sec_player = false;
        float music_volume = 1.0;
        std::vector<std::vector<int>> _map;
    private:
        int fps = 60;
        int width = 1000;
        int height = 750;
};

#endif /* !CORE_HPP_ */
