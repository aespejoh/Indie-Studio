/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Settings
*/

#include "Menus/Settings.hpp"
#include <stdlib.h>
#include <cmath>

Settings::Settings(Core *core)
{
    this->core = core;
    loadTexture();
    loadRect();
}

Settings::~Settings()
{
}

Menu Settings::menu()
{
    ClearBackground(WHITE);

    if (core == nullptr)
        exit(84);
    core->getSound().playMusic("hp");
    core->getCameraHandler().setTarget(0.0f, 0.0f, -2.5f);
    core->getCameraHandler().setPosition(0.0f, 7.5f, 12.5f);
    core->getLogic().update();
    core->getSound().update();
    core->getHandler().update();
    core->getBus()->notify();

    mousePoint = GetMousePosition();

    initInfo();
    checkMouse();
    playMouseCheck();
    drawing();

    if (playAction) {
        playAction = false;
        return MID;
    }
    return SETTINGS;
}

void Settings::checkMouse()
{
    if (CheckCollisionPointRec(mousePoint, arrow_left_rect)) {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && core->getMusicVolume() > 0) {
            float vol = core->getMusicVolume() - 0.10;
            core->setMusicVolume(vol);
            core->getSound().setMusicVolume("hp", vol);
        }
    }
    if (CheckCollisionPointRec(mousePoint, arrow_right_rect)) {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && core->getMusicVolume() < 1.0) {
            float vol = core->getMusicVolume() + 0.10;
            core->setMusicVolume(vol);
            core->getSound().setMusicVolume("hp", vol);
        }
    }
    if (CheckCollisionPointRec(mousePoint, arrow_left_rect_)) {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            switchFpsDes();
        }
    }
    if (CheckCollisionPointRec(mousePoint, arrow_right_rect_)) {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            switchFpsAsc();
        }
    }
}

void Settings::loadTexture()
{
    font = LoadFont("resources/font/Caramel Sweets.ttf");

    Image _background = LoadImage("resources/background_two.png");
    ImageResize(&_background, WIDTH + 100, HEIGHT + 100);
    background = LoadTextureFromImage(_background);

    Image left = LoadImage("resources/arrow_left.png");
    ImageResize(&left, 50, 50);
    arrow_left = LoadTextureFromImage(left);

    Image right = LoadImage("resources/arrow_right.png");
    ImageResize(&right, 50, 50);
    arrow_right = LoadTextureFromImage(right);

    Image _playButton = LoadImage("resources/buttons/playButton.png");
    ImageResize(&_playButton, 200, 125);
    playButton = LoadTextureFromImage(_playButton);
}

void Settings::loadRect()
{
    arrow_left_rect = {500, 180, (float)arrow_left.width,
                       (float)arrow_left.height};
    arrow_right_rect = {630, 180, (float)arrow_left.width,
                        (float)arrow_left.height};
    arrow_left_rect_ = {500, 240, (float)arrow_left.width,
                       (float)arrow_left.height};
    arrow_right_rect_ = {630, 240, (float)arrow_left.width,
                        (float)arrow_left.height};
}

void Settings::drawing()
{
    BeginDrawing();
    DrawTexture(background, -50, -50, WHITE);
    DrawTextEx(font, "SETTINGS", Vector2{(float)WIDTH/2 - 150, 30.0f}, 100, 2,
               BLACK);
    drawingMusicVolumen();
    drawingFpds();
    drawButton();
    EndDrawing();
}

void Settings::drawingFpds()
{
    int fpss = core->getFps();
    std::string ss = std::to_string(fpss);
    char const *fps = ss.c_str();

    DrawTextEx(font, "FPS:", Vector2{150.0f, 250.0f}, 50, 2, BLACK);
    DrawTexture(arrow_left, 500, 240, WHITE);
    DrawTextEx(font, fps, Vector2{560.0f, 245}, 50, 2, BLACK);
    DrawTexture(arrow_right, 630, 240, WHITE);
}

void Settings::drawingMusicVolumen()
{
    int vol = (int)round(core->getMusicVolume() * 100);
    std::string s = std::to_string(vol);
    char const *volume = s.c_str();

    DrawTextEx(font, "Music volume:", Vector2{150.0f, 190.0f}, 50, 2, BLACK);
    DrawTexture(arrow_left, 500, 180, WHITE);
    DrawTextEx(font, volume, Vector2{560.0f, 185}, 50, 2, BLACK);
    DrawTexture(arrow_right, 630, 180, WHITE);
}

void Settings::drawButton()
{
    DrawTextureRec(playButton, playSourceRec,
                   Vector2{ playBtnBounds.x, playBtnBounds.y }, WHITE);
}

void Settings::playMouseCheck()
{
    if (CheckCollisionPointRec(mousePoint, playBtnBounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            playState = 2;
        else
            playState = 1;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            playAction = true;
    }
    else playState = 0;

    if (playAction)
        core->getSound().playSound("button");
    playSourceRec.y = playState * playFrameHeight;
}

void Settings::initInfo()
{
    playFrameHeight = (float)playButton.height/NUM_FRAMES;

    playSourceRec = {0, 0, (float)playButton.width, playFrameHeight};

    playBtnBounds = {WIDTH/2.0f - playButton.width/2.0f,
                     HEIGHT/2.0f - playButton.height/NUM_FRAMES/2.0f + 250,
                     (float)playButton.width, playFrameHeight};
}

void Settings::switchFpsAsc()
{
    int fps = core->getFps();
    switch (fps) {
        case 30:
            core->setFps(60);
            SetTargetFPS(60);
            break;
        case 60:
            core->setFps(120);
            SetTargetFPS(120);
            break;
        case 120:
            core->setFps(30);
            SetTargetFPS(30);
            break;
    }
}

void Settings::switchFpsDes()
{
    int fps = core->getFps();
    switch (fps) {
        case 30:
            core->setFps(120);
            SetTargetFPS(120);
            break;
        case 60:
            core->setFps(30);
            SetTargetFPS(30);
            break;
        case 120:
            core->setFps(60);
            SetTargetFPS(60);
            break;
    }
}
