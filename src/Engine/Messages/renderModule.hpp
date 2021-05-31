/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_RENDERMODULE_HPP
#define INDIE_STUDIO_RENDERMODULE_HPP

#include "MessageNode.hpp"
#include <raylib.h>

class RenderModule : public MessageNode {
    public:
        explicit RenderModule(MessageBus *bus);
        void update() override;
        void renderMap();
    protected:
        void renderMapTile(Vector3 position);
        void onNotify(Msg message) override;
};

#endif //INDIE_STUDIO_RENDERMODULE_HPP
