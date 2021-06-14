/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Mid
*/

#ifndef MID_HPP_
#define MID_HPP_

#include "Parameters.hpp"

class Mid {
    public:
        explicit Mid(const Parameters& parameters);
        ~Mid();
        Menu menu();
        void setBus(const MessageBus &bus);
    private:
        Parameters parameters;
};

#endif /* !MID_HPP_ */
