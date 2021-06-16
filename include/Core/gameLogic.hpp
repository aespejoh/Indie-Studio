/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#ifndef INDIE_STUDIO_GAMELOGIC_HPP
#define INDIE_STUDIO_GAMELOGIC_HPP

#include "MsgNode.hpp"
#include "Player.hpp"

class GameLogic : public MsgNode {
    public:
        explicit GameLogic(MessageBus *msgBus);
        void update() override;
        Player *_player1;
        Player *_player2;
        Player *_player3;
        Player *_player4;
    private:
        void onNotify(Msg message) override;
};

#endif //INDIE_STUDIO_GAMELOGIC_HPP
