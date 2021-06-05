/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/

#include "Object.hpp"

Object::Object(int uniqueID) : ID(uniqueID)
{
}

void Object::loadComponent(BaseComponent *comp)
{
    _components.push_back(comp);
}

int Object::getID()
{
    return ID;
}

void Object::draw()
{
    for (const auto &item : _components) {
        if (item->getType() == RENDER)

    }
}
