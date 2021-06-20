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

bool MapModule::initialPlayerPos(int row, int col)
{
    if (row == 1 || row == MAX_ROW - 2) {
        if (col == 1 || col == MAX_ROW - 2)
            return (true);
    }
    return (false);
}

void MapModule::initWalls()
{
    for (int i = 0; i < MAX_ROW; ++i) {
        this->ascii_map[i][0] = MapCell::Wall;
        for (int j = 1; j < MAX_COL; ++j) {
            if (i == 0 || j == MAX_COL - 1 || i == MAX_ROW - 1)
                this->ascii_map[i][j] = MapCell::Wall;
            else if ((i % 2 == 0) && (j % 2 == 0))
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
    } while (!initialPlayerPos(i, j) && this->ascii_map[i][j] != MapCell::Empty);
    this->ascii_map[i][j] = MapCell::ExitWithBox;
}

void MapModule::initBoxes()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, MAX_ROW - 1);
    int numBoxes = 0;
    int i;
    int j;

    while (numBoxes <= MAX_BOXES) {
        i = dist(mt);
        j = dist(mt);
        if (!initialPlayerPos(i, j) && this->ascii_map[i][j] == MapCell::Empty) {
            this->ascii_map[i][j] = MapCell::Box;
            numBoxes++;
        }
    }
}

std::vector<Vector3> MapModule::generateBoxPositions()
{
    std::vector<Vector3> posList;

    for (int row = 0; row < MAX_ROW; ++row) {
        for (int col = 0; col < MAX_COL; ++col) {
            if (ascii_map[row][col] == MapCell::Box)
                posList.push_back(Vector3 {(float) row, 1.0f, (float) col});
        }
    }
    return (posList);
}

std::vector<Vector3> MapModule::generateWallPositions()
{
    std::vector<Vector3> posList;

    for (int row = 0; row < MAX_ROW; ++row) {
        for (int col = 0; col < MAX_COL; ++col) {
            if (ascii_map[row][col] == MapCell::Wall)
                posList.push_back(Vector3 {(float) row, 1.0f, (float) col});
        }
    }
    return (posList);
}

std::vector<Vector3> MapModule::getExitPosition()
{
    std::vector<Vector3> posList;

    for (int row = 0; row < MAX_ROW; ++row) {
        for (int col = 0; col < MAX_COL; ++col) {
            if (ascii_map[row][col] == MapCell::ExitWithBox)
                posList.push_back(Vector3 {(float) row, 1.0f, (float) col});
        }
    }
    return (posList);
}

void MapModule::generatePositionVectors()
{
    positions.clear();
    std::vector<Vector3> boxPositions = generateBoxPositions();
    std::vector<Vector3> wallPositions = generateWallPositions();

    positions.insert({"boxes", boxPositions});
    positions.insert({"walls", wallPositions});
    positions.insert({"exit", getExitPosition()});
}

void MapModule::generateMap()
{
    this->initWalls();
    this->initExit();
    this->initBoxes();
    this->generatePositionVectors();
}

void MapModule::printAsciiMap()
{
    for (int f = 0; this->ascii_map.size() != f; f++) {
        std::cerr << std::endl;
        for (int s = 0; this->ascii_map[f].size() != s; s++)
            std::cerr << this->ascii_map[f][s];
    }
}

const std::map<std::string, std::vector<Vector3>> &MapModule::getPositions() const
{
    return (positions);
}

bool MapModule::canPass(Vector3 &pos)
{
    int row = pos.x - (int) pos.x > 0.4 ? pos.x + 1 : pos.x;
    int col = pos.z - (int) pos.z > 0.4 ? pos.z + 1 : pos.z;

    std::cerr << "x " << pos.x << " row " << row << "\tz " << pos.z << " col " << col << std::endl;
    if (ascii_map[row][col] == MapCell::Empty)
        return (true);
    return (false);
}

int MapModule::cellType(Vector3 &pos)
{
    int row = pos.x - (int) pos.x > 0.4 ? pos.x + 1 : pos.x;
    int col = pos.z - (int) pos.z > 0.4 ? pos.z + 1 : pos.z;

    return (ascii_map[row][col]);
}

int MapModule::destroy(Vector3 pos)
{
    int ret = 0;
    int row = pos.x - (int) pos.x > 0.4 ? pos.x + 1 : pos.x;
    int col = pos.z - (int) pos.z > 0.4 ? pos.z + 1 : pos.z;
    int down = destroyDown(row, col);
    int left = destroyLeft(row, col);
    int right = destroyRight(row, col);
    int up = destroyUp(row, col);
    generatePositionVectors();
    down != 0 ? ret = down : down;
    left != 0 ? ret = left : left;
    right != 0 ? ret = right : right;
    up != 0 ? ret = up : up;
    return ret;
}

int MapModule::destroyUp(int row, int col)
{
    int ret = 0;
    for (int i = 0; ascii_map[row][col] != Wall; i++) {
        if (ascii_map[row][col] == Box)
            ascii_map[row][col] = Empty;
        if (ascii_map[row][col] >= Player1 && ascii_map[row][col] <= Player4)
            ret = ascii_map[row][col];
        col == 0 ? col : col--;
        if (i == 3)
            break;
    }
    return ret;
}

int MapModule::destroyDown(int row, int col)
{
    int ret = 0;
    for (int i = 0; ascii_map[row][col] != Wall; i++) {
        if (ascii_map[row][col] == Box)
            ascii_map[row][col] = Empty;
        if (ascii_map[row][col] >= Player1 && ascii_map[row][col] <= Player4)
            ret = ascii_map[row][col];
        col == MAX_COL ? col : col++;
        if (i == 3)
            break;
    }
    return ret;
}

int MapModule::destroyRight(int row, int col)
{
    int ret = 0;
    for (int i = 0; ascii_map[row][col] != Wall; i++) {
        if (ascii_map[row][col] == Box)
            ascii_map[row][col] = Empty;
        if (ascii_map[row][col] >= Player1 && ascii_map[row][col] <= Player4)
            ret = ascii_map[row][col];
        row == MAX_ROW ? row : row++;
        if (i == 3)
            break;
    }
    return ret;
}

int MapModule::destroyLeft(int row, int col)
{
    int ret = 0;
    for (int i = 0; ascii_map[row][col] != Wall; i++) {
        if (ascii_map[row][col] == Box)
            ascii_map[row][col] = Empty;
        if (ascii_map[row][col] >= Player1 && ascii_map[row][col] <= Player4)
            ret = ascii_map[row][col];
        row == 0 ? row : row--;
        if (i == 3)
            break;
    }
    return ret;
}

void MapModule::clearPlayerPos(Vector3 pos)
{
    int row = pos.x - (int) pos.x > 0.4 ? pos.x + 1 : pos.x;
    int col = pos.z - (int) pos.z > 0.4 ? pos.z + 1 : pos.z;
    ascii_map[row][col] = Empty;
}

void MapModule::putPlayerPos(Vector3 pos, int playerID)
{
    int row = pos.x - (int) pos.x > 0.4 ? pos.x + 1 : pos.x;
    int col = pos.z - (int) pos.z > 0.4 ? pos.z + 1 : pos.z;
    ascii_map[row][col] = Bomb + playerID;
}
