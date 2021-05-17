//
// Created by arnau on 17/05/2021.
//

#ifndef INDIE_STUDIO_INPUTHANDLER_HPP
#define INDIE_STUDIO_INPUTHANDLER_HPP

#include "MessageNode.hpp"

class InputHandler : public MessageNode {
    public:
        explicit InputHandler(MessageBus* msgBus);
        void update() override;
    private:
        void onNotify(Msg message) override;
};

#endif //INDIE_STUDIO_INPUTHANDLER_HPP
