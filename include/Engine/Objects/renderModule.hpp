/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_RENDERMODULE_HPP
#define INDIE_STUDIO_RENDERMODULE_HPP

#include "MsgNode.hpp"
#include <MapModule/mapModule.h>
#include <raylib.h>

class RenderModule : public MsgNode {
    public:
        explicit RenderModule(MessageBus *bus);
        void update() override;
        void renderMap(MapModule &map);
        void loadTextures();
    protected:
        void renderMapTile(Vector3 position);
        void onNotify(Msg message) override;
        Texture2D _wallTexture;
};

#endif //INDIE_STUDIO_RENDERMODULE_HPP
