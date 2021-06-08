/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** Created by aespejo,
*/

#include "MapModule/mapModule.h"

std::vector<std::string> MapModule::getFiles()
{
    DIR *dir;
    struct dirent *diread;
    std::vector<std::string>files;

    if ((dir = opendir("saves/")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr)
            files.emplace_back(diread->d_name);
        closedir(dir);
        return (files);
    } else {
        perror("opendir");
        files.emplace_back(std::string("empty"));
        return (files);
    }
}

std::string MapModule::getFileName()
{
    std::vector<std::string>files = getFiles();
    std::string tmp;
    std::string name = std::string("game");
    char num = 0;

    if (files.back() == "empty")
        return (std::string("game1.sav"));
    else if (files.back().length() > 9)
        return (std::string("error"));
    else {
        tmp = files.back();
        num = tmp[4];
        if (num - 48 == 9)
            return (std::string("game10.sav"));
        else {
            name.push_back((char) (num + 1));
            name.append(".sav");
            return (name);
        }
    }
}

void MapModule::saveMap(const std::string &game)
{
    std::ofstream save;
    std::string filename = (game == "empty") ? getFileName() : game;

    save.open(filename);
    if (save.is_open()) {
        for (size_t i = 0; i < MAX_ROW; ++i) {
            for (size_t j = 0; j < MAX_COL; ++j)
                save << this->ascii_map[i][j];
            save << std::endl;
        }
    }
    save.close();
}

void MapModule::loadMap(const std::string &filename)
{
    std::ifstream save;
    std::string line;
    size_t i = 0;

    save.open(filename);
    if (save.is_open()) {
        while (getline(save, line) && i != MAX_ROW) {
            for (size_t j = 0; j < MAX_COL; ++j)
                this->ascii_map[i][j] = (int)(line[j] - 48);
            ++i;
        }
    }
}