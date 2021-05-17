/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_MESSAGEBUS_HPP
#define INDIE_STUDIO_MESSAGEBUS_HPP

#include <vector>
#include <queue>
#include <functional>

typedef enum {
    OPEN_INVENTORY,
    PAUSE_GAME
}msgType;

class Msg {
    public:
        Msg() = default;
        ~Msg() = default;
        void setType(msgType type) {_type = type;};
        msgType getType() {return _type;};
    private:
        msgType _type;
};

class MessageBus {
    public:
        MessageBus() = default;
        ~MessageBus() = delete;
    void addReciever(std::function<void (Msg)> messageReceiver);
    void sendMessage(Msg message);
    void notify();
    private:
        std::vector<std::function<void (Msg)>> _receivers;
        std::queue<Msg> _messages;
};

#endif //INDIE_STUDIO_MESSAGEBUS_HPP
