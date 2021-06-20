/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Bomba
*/

#include "Bomba.hpp"
#include <algorithm>

Bomba::Bomba(Vector3 position, BombModel bombModel) : _position(position)
{
    _model = *bombModel.getModel();
}

void Bomba::draw()
{
    DrawModel(_model, _position, _scale, _color);
}

int Bomba::get_Tick() const
{
    return _tick;
}

void Bomba::addTick()
{
    _tick++;
}

bool Bomba::update()
{
    addTick();
    if (_tick > 100)
        return true;
    return false;
}

void Bomba::explode()
{

}

void BombModel::load_model_texture()
{
    _model = LoadModel(BOMB_MODEL_PATH);
    _texture = LoadTexture(BOMB_TEXTURE_PATH);
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}
