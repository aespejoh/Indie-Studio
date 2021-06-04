/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/

#ifndef BOMBERMAN_OBJECT_HPP
#define BOMBERMAN_OBJECT_HPP

#include "raylib.h"
#include <list>
#include "BaseComponent.hpp"

class Object {
    public:
        explicit Object(int uniqueID);
        int getID();
        void loadComponent(BaseComponent *comp);
    private:
        int ID;
        Vector3 _position;
        std::list<BaseComponent*> _components;
};

#endif //BOMBERMAN_OBJECT_HPP
