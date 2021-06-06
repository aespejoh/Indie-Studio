/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** CameraHandler
*/

#ifndef CAMERAHANDLER_HPP_
#define CAMERAHANDLER_HPP_

#include "MessageNode.hpp"
#include <raylib.h>

class CameraHandler : public MessageNode {
    public:
        explicit CameraHandler(MessageBus* msgBus);
        void update() override;
        void setFov(float val);
        void setTarget(float x, float y, float z);
        void setUp(float x, float y, float z);
        void setPosition(float x, float y, float z);
        void setProjection(int mode);
        void Begin3DMode();
        void End3DMode();

private:
        void onNotify(Msg message) override;
        Camera camera;
};

#endif /* !CAMERAHANDLER_HPP_ */
