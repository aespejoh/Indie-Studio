/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_CAMERAMODULE_HPP
#define INDIE_STUDIO_CAMERAMODULE_HPP

#include "MsgNode.hpp"
#include "raylib.h"

class CameraModule : public MsgNode{
    public:
        explicit CameraModule(MessageBus *bus);
        void switchCamera();

    private:
        Camera _mainCamera;
        Camera _secondaryCamera;
        Camera *_activeCamera;

};

#endif //INDIE_STUDIO_CAMERAMODULE_HPP
