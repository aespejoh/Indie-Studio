/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** soundHandler
*/

#include <SoundModule/SoundHandler.hpp>

SoundHandler::SoundHandler(MessageBus *msgBus) : MessageNode(msgBus) {

}

void SoundHandler::update() {
    std::map<std::string, Music>::iterator it;
    for (it = soundStorage.begin(); it != soundStorage.end(); it++)
        UpdateMusicStream(it->second);
    MessageNode::update();
}

void SoundHandler::onNotify(Msg message) {
    MessageNode::onNotify(message);
}

void SoundHandler::addSound(const std::string& name, const std::string& path) {
    std::ifstream f(path.c_str());
    if (!f.good())
        return;
    InitAudioDevice();
    Music music = LoadMusicStream(path.c_str());
    soundStorage.insert({name, music});
}

void SoundHandler::play(const std::string& name) {
    InitAudioDevice();
    PlayMusicStream(soundStorage.find(name)->second);
}

void SoundHandler::stop(const std::string& name) {
    StopMusicStream(soundStorage.find(name)->second);
}