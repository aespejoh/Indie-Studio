/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** CameraHandler
*/

#include "CameraModule/CameraHandler.hpp"

CameraHandler::CameraHandler(MessageBus *msgBus) : MsgNode(msgBus) {
    Camera camera = { 0 };
    this->camera = camera;
}

void CameraHandler::update() {
    UpdateCamera(&camera);
    MsgNode::update();
}

void CameraHandler::onNotify(Msg message) {
    MsgNode::onNotify(message);
}

void CameraHandler::setFov(float val) {
    camera.fovy = val;
}

void CameraHandler::setTarget(float x, float y, float z) {
    camera.target = Vector3{x, y, z};
}

void CameraHandler::setUp(float x, float y, float z) {
    camera.up = Vector3{x, y, z};
}

void CameraHandler::setPosition(float x, float y, float z) {
    camera.position = Vector3{x, y, z};
}

void CameraHandler::setProjection(int mode) {
    camera.projection = mode;
}

void CameraHandler::Begin3DMode() {
    BeginMode3D(camera);
}

void CameraHandler::End3DMode() {
    EndMode3D();
}
