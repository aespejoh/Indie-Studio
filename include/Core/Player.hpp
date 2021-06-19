/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Player
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include <MapModule/mapModule.h>

#define MODEL_PLAYER_PATH "resources/bomberman/Bomberman.obj"
#define TEXTURE_BLUE_PLAYER_PATH "resources/bomberman/blue_body.png"
#define TEXTURE_BLACK_PLAYER_PATH "resources/bomberman/black_body.png"
#define TEXTURE_YELLOW_PLAYER_PATH "resources/bomberman/yellow_body.png"
#define TEXTURE_RED_PLAYER_PATH "resources/bomberman/red_body.png"

class Player
{
    public:
        explicit Player(int playerID, MapModule &map);
        void draw();
        void moveUp();
        void moveLeft();
        void moveRight();
        void moveDown();
        const Vector3 &getPosition() const;

    private:
        void load_model_and_texture(int player_num);
        MapModule _map;
        Model _model;
        Texture _texture;
        Vector3 _position = {5.0f, 0.0f, 5.0f};
        BoundingBox _boundingBox;
        float _scale = 0.075f;
        Color _color = WHITE;
        int _player_ID;
        float _pitch = 0.0f;
        float _roll = 0.0f;
        float _yaw = 0.0f;
};

#endif