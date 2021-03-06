/*
** EPITECH PROJECT, 2021
** indie_studio
** File description:
**
*/

#ifndef BOMBERMAN_MAPMODULE_H
#define BOMBERMAN_MAPMODULE_H

#ifdef __unix__
    #include <dirent.h>
#elif defined(_WIN32) || defined(WIN32)
    #include "dirent_win.h"
#endif
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <raylib.h>
#include <map>
#include <string>

#define MAX_COL 15
#define MAX_ROW 15
#define MAX_BOXES 30

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
    std::map<std::string, std::vector<Vector3>> positions;

public:
    const std::map<std::string, std::vector<Vector3>> &getPositions() const;

public:
    MapModule();
    ~MapModule() = default;
    void saveMap(const std::string& game = std::string("empty"));
    void loadMap(const std::string &filename);
    void generateMap();
    void printAsciiMap();
    bool canPass(Vector3 &pos, Vector3 &player, int playerId);
    int cellType(Vector3 &pos);
    int destroy(Vector3 pos);
    void clearPlayerPos(Vector3 pos);
    void putPlayerPos(Vector3 pos, int playerID);

private:
    int destroyUp(int row, int col);
    int destroyDown(int row, int col);
    int destroyRight(int row, int col);
    int destroyLeft(int row, int col);
    static std::string lastFile(std::vector<std::string> files);
    static std::string getFile();
    static std::string getFileName();
    static bool initialPlayerPos(int row, int col);
    void initWalls();
    void initExit();
    void initBoxes();
    std::vector<Vector3> generateBoxPositions();
    std::vector<Vector3> generateWallPositions();
    std::vector<Vector3> getExitPosition();
    void generatePositionVectors();
    bool checkMap(int row, int col, int playerId);
};


#endif //BOMBERMAN_MAPMODULE_H
