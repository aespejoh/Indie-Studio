/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/
#include "RenderComponent.hpp"

void RenderComponent::load_model(std::string path)
{
    _model = LoadModel(path.c_str());
}

void RenderComponent::load_texture(std::string path)
{
    _texture = LoadTexture(path.c_str());
}

RenderComponent::RenderComponent()
{

}
