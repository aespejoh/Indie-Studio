/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Player
*/

#include "Player.hpp"

void Player::load_model_and_texture()
{
    _model = LoadModel(MODEL_PLAYER_PATH);
    _texture = LoadTexture(TEXTURE_BLACK_PLAYER_PATH);
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
}

void Player::draw()
{
    DrawModel(_model, _position, _scale, _color);
}

Player::Player(int playerID) : _player_ID(playerID)
{
}
