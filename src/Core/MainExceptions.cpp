/*
** EPITECH PROJECT, 2021
** B-YEP-400-BAR-4-1-indiestudio-arnau.espejo-hernandez
** File description:
** Exceptions
*/

#include "MainExceptions.hpp"

MainException::MainException()
{
    exceptionMessage = "An exception has ocurred";
}

MainException::MainException(std::string str)
{
    exceptionMessage = str;
}

char const *MainException::what() const noexcept
{
    return exceptionMessage.c_str();
}