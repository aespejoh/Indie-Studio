/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** soundHandler
*/

#include <SoundModule/SoundHandler.hpp>

SoundHandler::SoundHandler(MessageBus *msgBus) : MessageNode(msgBus) {
    InitAudioDevice();
}

SoundHandler::~SoundHandler() {
    std::map<std::string, Music>::iterator musicIt;
    std::map<std::string, Sound>::iterator soundIt;

    CloseAudioDevice();
    for (musicIt = musicStorage.begin(); musicIt != musicStorage.end(); musicIt++)
        UnloadMusicStream(musicIt->second);
    for (soundIt = soundStorage.begin(); soundIt != soundStorage.end(); soundIt++)
        UnloadSound(soundIt->second);
}

void SoundHandler::update() {
    std::map<std::string, Music>::iterator it;
    for (it = musicStorage.begin(); it != musicStorage.end(); it++)
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
    Sound sound = LoadSound(path.c_str());
    soundStorage.insert({name, sound});
}

void SoundHandler::addMusic(const std::string& name, const std::string& path) {
    std::ifstream f(path.c_str());
    if (!f.good())
        // TODO: Set return type to right exception
        return;
    Music music = LoadMusicStream(path.c_str());
    musicStorage.insert({name, music});
}

void SoundHandler::playSound(const std::string& name) {
    PlaySound(soundStorage.find(name)->second);
}

void SoundHandler::playMusic(const std::string& name) {
    PlayMusicStream(musicStorage.find(name)->second);
}

void SoundHandler::stopMusic(const std::string& name) {
    StopMusicStream(musicStorage.find(name)->second);
}

void SoundHandler::stopSound(const std::string& name) {
    StopSound(soundStorage.find(name)->second);
}