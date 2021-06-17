/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(Vector3 position) : _position(position)
{
    load_model_and_texture();
}

void Bomb::load_model_and_texture()
{
    _model = LoadModel(BOMB_MODEL_PATH);
    _texture = LoadTexture(BOMB_TEXTURE_PATH);
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
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

