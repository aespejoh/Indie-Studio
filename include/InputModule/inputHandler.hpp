//
// Created by arnau on 17/05/2021.
//

#ifndef INDIE_STUDIO_INPUTHANDLER_HPP
#define INDIE_STUDIO_INPUTHANDLER_HPP

#include "MessageNode.hpp"
#include <raylib.h>

class InputHandler : public MessageNode {
    public:
        explicit InputHandler(MessageBus* msgBus);
        void update() override;
        void handleInput(int);
    private:
        void onNotify(Msg message) override;
        std::vector<std::pair<int, msgType>> _keyBinds;
};

#endif //INDIE_STUDIO_INPUTHANDLER_HPP
