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

    for (auto & boxPosition : boxes)
        DrawCube(boxPosition, 1.0f, 1.0f, 1.0f, BLUE);
    for (auto & colPosition : walls)
        DrawCube(colPosition, 1.0f, 1.0f, 1.0f, GREEN);
}
