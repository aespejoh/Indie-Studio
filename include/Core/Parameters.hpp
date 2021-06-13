/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Parameters
*/

#ifndef PARAMETERS_HPP_
#define PARAMETERS_HPP_

class Parameters {
    public:
        Parameters();
        ~Parameters();
        int getFps() const;
        void setFps(int fps);

    private:
        int fps;

};

#endif /* !PARAMETERS_HPP_ */