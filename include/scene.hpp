/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_SCENE_HPP
#define INDIE_STUDIO_SCENE_HPP

#include "raylib.h"

class Scene {
    public:
        Scene();
        ~Scene() = default;
        Camera getCamera() {return _camera;};
        void setCameraPosition(Vector3);
    private:
        Camera _camera;
};

#endif //INDIE_STUDIO_SCENE_HPP
