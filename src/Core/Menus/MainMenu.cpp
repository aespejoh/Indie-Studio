/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** MainMenu
*/

#include "Menus/MainMenu.hpp"

MainMenu::MainMenu(Core *core)
{
    this->core = core;
}

MainMenu::~MainMenu()
{
}

int MainMenu::display() {
    core->getSound().playMusic("hp2");
    return MAIN;
}