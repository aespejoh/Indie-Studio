/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "Objects/renderModule.hpp"

RenderModule::RenderModule(MessageBus *bus) : MsgNode(bus)
{

}

void RenderModule::update()
{

}

void RenderModule::onNotify(Msg message)
{

}

void RenderModule::renderMapTile(Vector3 position)
{
    DrawCube(position, 1, 1, 1, BLACK);
}

void RenderModule::renderMap(MapModule &map)
{
    std::vector<Vector3> boxes = map.getPositions().at("boxes");
    std::vector<Vector3> walls = map.getPositions().at("walls");
    Vector3 exit = map.getPositions().at("exit").back();
    Vector3 size = {1.0f, 1.0f, 1.0f};
    Texture2D wallTexture = LoadTexture("resources/cubicmap_atlas.png");

    for (auto & boxPosition : boxes)
        DrawCubeV(boxPosition, size, BLUE);
    for (auto & colPosition : walls)
        DrawCubeTexture(wallTexture, colPosition, 1.0f, 1.0f, 1.0f, GRAY);
    DrawCubeTexture(wallTexture, exit, 1.0f, 1.0f, 1.0f, RED);
}
