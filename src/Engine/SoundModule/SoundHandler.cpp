/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** soundHandler
*/

#include <SoundModule/SoundHandler.hpp>

SoundHandler::SoundHandler(MessageBus *msgBus) : MsgNode(msgBus) {
    InitAudioDevice();
}

SoundHandler::~SoundHandler()
{
    CloseAudioDevice();
    if (!musicStorage.empty()) {
        for (const auto &item : musicStorage)
            UnloadMusicStream(item.second);
    }
    if (!soundStorage.empty()) {
        for (const auto &item : soundStorage)
            UnloadSound(item.second);
    }
}

void SoundHandler::update() {
    std::map<std::string, Music>::iterator it;
    for (it = musicStorage.begin(); it != musicStorage.end(); it++)
        UpdateMusicStream(it->second);
    MsgNode::update();
}

void SoundHandler::onNotify(Msg message) {
    MsgNode::onNotify(message);
}

void SoundHandler::setMusicVolume(const std::string& name, float volume)
{
    SetMusicVolume(musicStorage.find(name)->second, volume);
}

void SoundHandler::setSoundVolume(const std::string& name, float volume)
{
    SetSoundVolume(soundStorage.find(name)->second, volume);
}

void SoundHandler::addSound(const std::string& name, const std::string& path) {
    std::ifstream f(path.c_str());
    if (!f.good())
        throw MainException("A sound file hasn't been found");
    Sound sound = LoadSound(path.c_str());
    soundStorage.insert({name, sound});
}

void SoundHandler::addMusic(const std::string& name, const std::string& path) {
    std::ifstream f(path.c_str());
    if (!f.good())
        throw MainException("A music file hasn't been found");
    Music music = LoadMusicStream(path.c_str());
    musicStorage.insert({name, music});
}

void SoundHandler::playSound(const std::string& name) {
    PlaySound(soundStorage.find(name)->second);
}

void SoundHandler::playMusic(const std::string& name)
{
    if (playedBGM != name and !playedBGM.empty())
        stopMusic(playedBGM);
    playedBGM = name;
    PlayMusicStream(musicStorage.find(name)->second);
}

void SoundHandler::stopMusic(const std::string& name) {
    StopMusicStream(musicStorage.find(name)->second);
}

void SoundHandler::stopSound(const std::string& name) {
    StopSound(soundStorage.find(name)->second);
}