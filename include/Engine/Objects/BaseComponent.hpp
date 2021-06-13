/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/
#ifndef BOMBERMAN_BASECOMPONENT_HPP
#define BOMBERMAN_BASECOMPONENT_HPP

#include "raylib.h"
#include "string"

enum ComponentType {
    RENDER
};

class Object;
class BaseComponent {
    public:
        ComponentType getType() {return _type;};
        virtual void draw() = 0;
    protected:
        Object* _parent_object;
        ComponentType _type;

};

#endif //BOMBERMAN_BASECOMPONENT_HPP
