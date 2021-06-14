/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/
#include "Engine/Objects/RenderComponent.hpp"
#include "Objects/Object.hpp"

void RenderComponent::load_model(std::string path)
{
    _model = LoadModel(path.c_str());
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}

void RenderComponent::load_texture(std::string path)
{
    _texture = LoadTexture(path.c_str());
}

RenderComponent::RenderComponent(Object *parent)
{
    _parent_object = parent;
    _color = WHITE;
    _type = RENDER;
}

void RenderComponent::draw()
{
    DrawModel(_model, _parent_object->getPosition(), 0.005f, _color);
}
