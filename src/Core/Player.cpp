/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Player
*/

#include "Player.hpp"
#include "raymath.h"

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

void Player::moveUp()
{
    _position.z -= 0.05f;
    if (_yaw < 180.0f)
        _yaw += 10.0f;
    _model.transform = MatrixRotateXYZ(Vector3 { DEG2RAD* _pitch, DEG2RAD* _yaw, DEG2RAD* _roll });
}

void Player::moveLeft()
{
    _position.x -= 0.05f;
    if (_yaw < 90)
        _yaw += 10.0f;
    else if (_yaw > 90)
        _yaw -= 10.0f;
    _model.transform = MatrixRotateXYZ(Vector3 { DEG2RAD* _pitch, DEG2RAD* _yaw, DEG2RAD* _roll });
}

void Player::moveRight()
{
    _position.x += 0.05f;
    if (_yaw < 270)
        _yaw += 10.0f;
    else if (_yaw > 270)
        _yaw -= 10.0f;
    _model.transform = MatrixRotateXYZ(Vector3 { DEG2RAD* _pitch, DEG2RAD* _yaw, DEG2RAD* _roll });
}

void Player::moveDown()
{
    _position.z += 0.05f;
    if (_yaw > 0)
        _yaw -= 10.0f;
    _model.transform = MatrixRotateXYZ(Vector3 { DEG2RAD* _pitch, DEG2RAD* _yaw, DEG2RAD* _roll });
}
