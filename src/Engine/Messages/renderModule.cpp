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

void RenderModule::renderMap()
{

}

void RenderModule::renderMapTile(Vector3 position)
{
    DrawCube(position, 1, 1, 1, BLACK);
}
