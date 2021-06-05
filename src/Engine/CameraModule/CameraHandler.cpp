/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** CameraHandler
*/

#include "CameraModule/CameraHandler.hpp"

CameraHandler::CameraHandler(MessageBus *msgBus) : MessageNode(msgBus) {

}

void CameraHandler::update() {
    MessageNode::update();
}

void CameraHandler::onNotify(Msg message) {
    MessageNode::onNotify(message);
}