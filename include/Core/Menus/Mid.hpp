/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Mid
*/

#ifndef MID_HPP_
#define MID_HPP_

#include "Core.hpp"

class Mid {
    public:
        explicit Mid(Core *core);
        ~Mid();
        Menu menu();
    private:
        Core *core;
};

#endif /* !MID_HPP_ */
