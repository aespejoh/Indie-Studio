/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** soundHandler
*/

#ifndef SOUNDHANDLER_HPP_
#define SOUNDHANDLER_HPP_

#include <raylib.h>
#include <fstream>
#include "MessageNode.hpp"

class SoundHandler : public MessageNode {
    public:
        explicit SoundHandler(MessageBus* msgBus);
        ~SoundHandler();
        void update() override;
        void addSound(const std::string& name, const std::string& path);
        void addMusic(const std::string& name, const std::string& path);
        void playMusic(const std::string &name);
        void playSound(const std::string &name);
        void stopMusic(const std::string& name);
        void stopSound(const std::string& name);

    private:
        void onNotify(Msg message) override;
        std::map<std::string, Sound> soundStorage;
        std::map<std::string, Music> musicStorage;
};

#endif /* !SOUNDHANDLER_HPP_ */