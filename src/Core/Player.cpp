/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Player
*/

#include "Player.hpp"
#include "raymath.h"

void Player::load_model_and_texture(int player_num)
{
    switch (player_num) {
    case 1:
        _model = LoadModel(MODEL_PLAYER_PATH);
        _texture = LoadTexture(TEXTURE_BLACK_PLAYER_PATH);
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
        break;
    case 2:
        _model = LoadModel(MODEL_PLAYER_PATH);
        _texture = LoadTexture(TEXTURE_BLUE_PLAYER_PATH);
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
        break;
    case 3:
        _model = LoadModel(MODEL_PLAYER_PATH);
        _texture = LoadTexture(TEXTURE_YELLOW_PLAYER_PATH);
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
        break;
    case 4:
        _model = LoadModel(MODEL_PLAYER_PATH);
        _texture = LoadTexture(TEXTURE_RED_PLAYER_PATH);
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
        break;
    default:
        break;
    }
}

void Player::draw()
{
    DrawModel(_model, _position, _scale, _color);
}

Player::Player(int playerID, MapModule &map) : _player_ID(playerID), _map(map)
{
    load_model_and_texture(_player_ID);
}

void Player::moveUp()
{
    Vector3 pos = this->_position;
    pos.z -= 0.05f;

    if (_map.canPass(pos)) {
        _position.z -= 0.05f;
        if (_yaw < 180.0f)
            _yaw += 10.0f;
        if (_yaw > 180.0f)
            _yaw -= 10.0f;
        _model.transform = MatrixRotateXYZ(Vector3{DEG2RAD * _pitch, DEG2RAD * _yaw, DEG2RAD * _roll});
    }
}

void Player::moveLeft()
{
    Vector3 pos = this->_position;
    pos.x -= 0.05f;

    if (_map.canPass(pos)) {
        _position.x -= 0.05f;
        if (_yaw < 90)
            _yaw += 10.0f;
        else if (_yaw > 90)
            _yaw -= 10.0f;
        _model.transform = MatrixRotateXYZ(Vector3{DEG2RAD * _pitch, DEG2RAD * _yaw, DEG2RAD * _roll});
    }
}

void Player::moveRight()
{
    Vector3 pos = this->_position;
    pos.x += 0.05f;

    if (_map.canPass(pos)) {
        _position.x += 0.05f;
        _yaw == 0 ? _yaw = 360 : _yaw;
        if (_yaw < 270)
            _yaw += 10.0f;
        else if (_yaw > 270)
            _yaw -= 10.0f;
        _model.transform = MatrixRotateXYZ(Vector3{DEG2RAD * _pitch, DEG2RAD * _yaw, DEG2RAD * _roll});
    }
}

void Player::moveDown()
{
    Vector3 pos = this->_position;
    pos.z += 0.05f;

    if (_map.canPass(pos)) {
        _position.z += 0.05f;
        _yaw == 360 ? _yaw = 0 : _yaw;
        if (_yaw >= 270)
            _yaw += 10.0f;
        else if (_yaw > 0)
            _yaw -= 10.0f;
        _model.transform = MatrixRotateXYZ(Vector3{DEG2RAD * _pitch, DEG2RAD * _yaw, DEG2RAD * _roll});
    }
}

const Vector3 &Player::getPosition() const
{
    return _position;
}
