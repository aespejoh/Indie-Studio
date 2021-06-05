/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** CameraHandler
*/

#ifndef CAMERAHANDLER_HPP_
#define CAMERAHANDLER_HPP_

#include "MessageNode.hpp"

class CameraHandler : public MessageNode {
    public:
        explicit CameraHandler(MessageBus* msgBus);
        void update() override;

private:
        void onNotify(Msg message) override;
};

#endif /* !CAMERAHANDLER_HPP_ */
