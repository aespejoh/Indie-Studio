/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
** MapModule
*/

#include <cstring>
#include "MapModule/mapModule.h"

MapModule::MapModule()
{
    std::vector<std::vector<int>> map(MAX_ROW, std::vector<int>(MAX_COL, -1));

    this->ascii_map = map;
}

std::string MapModule::lastFile(std::vector<std::string> files)
{
    int pos = 0;
    std::string last;
    int num = 0;

    if (files.empty())
        return ("empty");
    for (auto it = files.begin(); it != files.end(); ++it) {
        if (it->at(4) - 48 > num) {
            num = it->at(4) - 48;
            pos = it - files.begin();
        }
    }
    last = files.at(pos);
    return (last);
}

std::string MapModule::getFile()
{
    DIR *dir;
    struct dirent *diread;
    std::vector<std::string>files;

    if ((dir = opendir("saves/")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if (strcmp(diread->d_name, ".") != 0 &&
                strcmp(diread->d_name, "..") != 0)
                files.emplace_back(diread->d_name);
        }
        closedir(dir);
        return (lastFile(files));
    } else {
        perror("opendir");
        return ("empty");
    }
}

std::string MapModule::getFileName() {
    std::string file = getFile();
    std::string name = std::string("game");
    char num = 0;

    if (file == "empty")
        return (std::string("game1.sav"));
    else if (file.length() > 9)
        return (std::string("error"));
    else {
        num = file[4];
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

    save.open("saves/" + filename);
    if (save.is_open()) {
        for (size_t i = 0; i < MAX_ROW; ++i) {
            for (size_t j = 0; j < MAX_COL; ++j)
                save << this->ascii_map[i][j];
            save << std::endl;
        }
    }
    save.close();
    std::cerr << "GAME SAVED" << std::endl;
}

void MapModule::loadMap(const std::string &filename)
{
    std::ifstream save;
    std::string line;
    size_t i = 0;

    save.open("saves/" + filename);
    if (save.is_open()) {
        while (getline(save, line) && i != MAX_ROW) {
            for (size_t j = 0; j < MAX_COL; ++j)
                this->ascii_map[i][j] = (int)(line[j] - 48);
            ++i;
        }
    }
}

void MapModule::initWalls()
{
    for (int i = 0; i < MAX_ROW; ++i) {
        this->ascii_map[i][0] = MapCell::Wall;
        for (int j = 1; j < MAX_COL; ++j) {
            if (i == 0 || j == MAX_COL - 1 || i == MAX_ROW - 1)
                this->ascii_map[i][j] = MapCell::Wall;
            else if (i % 2 == 0 and j % 2 == 0)
                this->ascii_map[i][j] = MapCell::Wall;
            else
                this->ascii_map[i][j] = MapCell::Empty;
        }
    }
}

void MapModule::initExit()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, MAX_ROW - 2);
    int i;
    int j;

    do {
        i = dist(mt);
        j = dist(mt);
    } while (this->ascii_map[i][j] != MapCell::Empty);
    this->ascii_map[i][j] = MapCell::ExitWithBox;
}

void MapModule::initBoxes()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    int numBoxes = 0;

    while (numBoxes <= MAX_BOXES) {
        for (int i = 1; i < MAX_ROW - 1; ++i) {
            for (int j = 1; j < MAX_ROW - 1; ++j) {
                if (this->ascii_map[i][j] == MapCell::Empty) {
                    if (numBoxes <= MAX_BOXES and dist(mt) == 1) {
                        this->ascii_map[i][j] = MapCell::Box;
                        numBoxes++;
                    }
                }
            }
        }
    }
}

void MapModule::generateMap()
{
    this->initWalls();
    this->initExit();
    this->initBoxes();
}