/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Bomb
*/

#ifndef BOMB_HPP
#define BOMB_HPP

#include "raylib.h"

#define BOMB_MODEL_PATH "resources/bomb/bomb.gltf"
#define BOMB_TEXTURE_PATH "resources/bomb/Normal.png"

class BombModel
{
    public:
        void load_model_texture();
        Model *getModel() {return &_model;};
        Texture *getTexture() {return &_texture;};
    private:
        Model _model;
        Texture _texture;
};

class Bomb {
    public:
        explicit Bomb(Vector3 position, BombModel bombModel);
        void draw();
        int get_Tick() const;
        bool update();
        void explode();
    private:
        void addTick();
        Vector3 _position;
        Model _model;
        Texture *_texture;
        float _scale = 5.0f;
        Color _color;
        int _tick = 0;
};

#endif