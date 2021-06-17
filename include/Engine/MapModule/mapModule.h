/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
**
*/

#ifndef BOMBERMAN_MAPMODULE_H
#define BOMBERMAN_MAPMODULE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <random>

#define MAX_COL 15
#define MAX_ROW 15
#define MAX_BOXES 40

enum MapCell {
    Empty,
    Wall,
    Box,
    Exit,
    ExitWithBox,
    Bomb,
    Player1,
    Player2,
    Player3,
    Player4,
    Enemy1,
    Enemy2,
    Enemy3,
    BoostBox
};

class MapModule {
private:
    std::vector<std::vector<int>> ascii_map;

public:
    MapModule();
    ~MapModule() = default;
    void saveMap(const std::string& game = std::string("empty"));
    void loadMap(const std::string &filename);
    void generateMap();
    void printMap();


private:
    static std::string lastFile(std::vector<std::string> files);
    static std::string getFile();
    static std::string getFileName();
    void initWalls();
    void initExit();
    void initBoxes();
};


#endif //BOMBERMAN_MAPMODULE_H
