//
// Created by arnau on 17/05/2021.
//

#ifndef INDIE_STUDIO_INPUTHANDLER_HPP
#define INDIE_STUDIO_INPUTHANDLER_HPP

#include "MsgNode.hpp"
#include <raylib.h>

class InputHandler : public MsgNode {
    public:
        explicit InputHandler(MessageBus* msgBus);
        void update() override;
        void addKeybind(int keycode, msgType action);
    private:
        void onNotify(Msg message) override;
        std::vector<std::pair<int, msgType>> _keyBinds;
};

#endif //INDIE_STUDIO_INPUTHANDLER_HPP
