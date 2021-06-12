/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include "Parameters.hpp"

class MainMenu {
    public:
        explicit MainMenu(const Parameters& parameters);
        ~MainMenu();
        void menu();
        Parameters &getParameters();
        void setParameters(const Parameters &parameters);
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
        Parameters parameters;
};

#endif /* !MAINMENU_HPP_ */
