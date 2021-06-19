/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include <algorithm>

Bomb::Bomb(Vector3 position, BombModel bombModel) : _position(position)
{
    _model = *bombModel.getModel();
}

void Bomb::draw()
{
    DrawModel(_model, _position, _scale, _color);
}

int Bomb::get_Tick() const
{
    return _tick;
}

void Bomb::addTick()
{
    _tick++;
}

#include <iostream>

bool Bomb::update()
{
    addTick();
    if (_tick > 100)
        return true;
    return false;
}

void Bomb::explode()
{

}

void BombModel::load_model_texture()
{
    _model = LoadModel(BOMB_MODEL_PATH);
    _texture = LoadTexture(BOMB_TEXTURE_PATH);
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}
