/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/
#ifndef BOMBERMAN_SCENEMANAGER_HPP
#define BOMBERMAN_SCENEMANAGER_HPP

#include "Object.hpp"
#include <map>

class SceneManager {
    public:
        Object *CreateObject();
    protected:
        std::map<int, Object*> _objects;
        int _objectID_count;
};

#endif //BOMBERMAN_SCENEMANAGER_HPP
