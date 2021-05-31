/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/
#include "console.hpp"

Console::Console()
{

}

void Console::update()
{
    std::cin >> _command;
    std::cout << _command << std::endl;
}
