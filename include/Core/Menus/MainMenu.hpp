/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** MainMenu
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#include <Core.hpp>

class MainMenu {
    public:
        MainMenu(Core *core);
        ~MainMenu();
        int display();

    private:
        Core *core;
};

#endif /* !MAINMENU_HPP_ */
