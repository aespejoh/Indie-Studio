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

class Bomb {
    public:
        explicit Bomb(Vector3 position);
        void draw();
        int get_Tick() const;
        void addTick();
    private:
        void load_model_and_texture();
        Vector3 _position;
        Model _model;
        Texture _texture;
        float _scale = 5.0f;
        Color _color;
        int _tick;
};

#endif