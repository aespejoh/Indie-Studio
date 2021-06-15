/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Mid
*/

#ifndef MID_HPP_
#define MID_HPP_

#include "Core.hpp"

#define WIDTH 1000
#define HEIGHT 750

class Mid {
    public:
        explicit Mid(Core *core);
        ~Mid();
        Menu menu();
        void loadTexture();
        void drawings();
        void setPositions();
    private:
        Core *core;
        Model boomberman_blue;
        Model boomberman_black;
        Model boomberman_yellow;
        Model boomberman_red;
        Texture2D blue;
        Texture2D black;
        Texture2D yellow;
        Texture2D red;
        Texture2D arrow_left;
        Texture2D arrow_right;
        Vector3 position;
        Vector3 position_two;
        Vector3 position_three;
        Vector3 position_four;
        Font font;
};

#endif /* !MID_HPP_ */
