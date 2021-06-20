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
#include "Bomba.hpp"

class GameLogic : public MsgNode {
    public:
        explicit GameLogic(MessageBus *msgBus);
        void update() override;
        void add_bomb(Bomba*);
        BombModel *getBombModel();
        void loadMap(MapModule *);
        const std::vector<Bomba *> &getBombs() const;
        void damage(Vector3 bombPosition);
        Player *_player1;
        Player *_player2;
        Player *_player3;
        Player *_player4;
    private:
        std::vector<Player*> _players;
        BombModel bombModel;
        MapModule *_map;
        void onNotify(Msg message) override;
        std::vector<Bomba*> _bombs;
        int _bombCooldown1 = 0;
        int _bombCooldown2 = 0;
};

#endif //INDIE_STUDIO_GAMELOGIC_HPP
