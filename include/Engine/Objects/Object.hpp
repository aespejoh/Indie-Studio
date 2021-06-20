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
#include "MsgNode.hpp"

class Object {
    public:
        explicit Object(int uniqueID);
        int getID();
        void loadComponent(BaseComponent *comp);
        void setPosition(Vector3 position);
        Vector3 getPosition() {return  _position;};
        void draw();
    private:
        int ID;
        Vector3 _position = {0,0,0};
        std::list<BaseComponent*> _components;
};

#endif //BOMBERMAN_OBJECT_HPP
