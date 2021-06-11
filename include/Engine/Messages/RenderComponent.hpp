/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by aespejo,
*/
#ifndef BOMBERMAN_RENDERCOMPONENT_HPP
#define BOMBERMAN_RENDERCOMPONENT_HPP

#include "Objects/BaseComponent.hpp"

class RenderComponent : public BaseComponent {
    public:
        RenderComponent();
        void load_model(std::string path);
        void load_texture(std::string path);
        void draw();

    private:
        Model _model;
        Texture _texture;
        Color _color;
};

#endif //BOMBERMAN_RENDERCOMPONENT_HPP
