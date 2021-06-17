/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Settings
*/

#include "Menus/Settings.hpp"
#include <stdlib.h>

Settings::Settings(Core *core)
{
    this->core = core;
    loadTexture();
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
    core->getBus().notify();

    checkMouse();
    //std::cout << core->getMusicVolume() << std::endl;
    int vol = (int)core->getMusicVolume() * 100;
    std::string s = std::to_string(vol);
    char const *pchar = s.c_str();

    BeginDrawing();
    DrawTexture(background, -50, -50, WHITE);
    DrawTextEx(font, "SETTINGS", Vector2{(float)WIDTH/2 - 100, 30.0f}, 50, 2,
               BLACK);
    DrawTextEx(font, "Music volume:", Vector2{250.0f, 190.0f}, 35, 2, BLACK);
    DrawTexture(arrow_left, 500, 180, WHITE);
    DrawTextEx(font, pchar, Vector2{560.0f, 190}, 35, 2, BLACK);
    DrawTexture(arrow_right, 610, 180, WHITE);
    //DrawTextEx(font, "-", Vector2{360, 170}, 75, 2, BLACK);
    //DrawTextEx(font, "+", Vector2{450, 170}, 75, 2, BLACK);
    /*for (int i = 0; i <= vol; i++) {
        DrawTextEx(font, "|", Vector2{posX, posY}, 40, 2, BLACK);
        posX += 10;
    }*/
    //DrawTextEx(font, "Music volume:", Vector2{130.0f, 190.0f}, 35, 2, BLACK);
    //core->getCameraHandler().Begin3DMode();
    //DrawCube(Vector3{-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
    //core->getCameraHandler().End3DMode();
    EndDrawing();
    return SETTINGS;
}

void Settings::checkMouse()
{
    if (CheckCollisionPointRec(mousePoint, arrow_left_rect)) {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            float vol = core->getMusicVolume() - 0.10;
            std::cout << vol << std::endl;
            core->setMusicVolume(vol);
            std::cout << core->getMusicVolume() << std::endl;
            core->getSound().setMusicVolume("hp", vol);
            std::cout << core->getMusicVolume() << std::endl;
        }
    }
    if (CheckCollisionPointRec(mousePoint, arrow_right_rect)) {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && core->getMusicVolume() < 1.0) {
            float vol = core->getMusicVolume() + 0.10;
            core->setMusicVolume(vol);
            core->getSound().setMusicVolume("hp", vol);
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
}
