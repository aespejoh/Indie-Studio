/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Parameters
*/

#include "Parameters.hpp"

Parameters::Parameters()
{
    fps = 60;
}

Parameters::~Parameters()
{
}

int Parameters::getFps() const {
    return fps;
}

void Parameters::setFps(int fps) {
    this->fps = fps;
}
