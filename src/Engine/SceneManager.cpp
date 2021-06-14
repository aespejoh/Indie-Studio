/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/
#include "SceneManager.hpp"

Object *SceneManager::CreateObject()
{
    Object *new_object = new Object(_objectID_count++);
    _objects.insert(std::make_pair(new_object->getID(), new_object));
    return new_object;
}

const std::map<int, Object *> &SceneManager::getObjects() const
{
    return _objects;
}
