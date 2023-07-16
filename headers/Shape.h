#pragma once
#include <vector>
#include "Block.h"
using namespace std;
class Shape{
public:
    vector<Block> blocks;
    vector<vector<vector<int>>> rotations;
    char type;
    int rotation;
    Shape();
    int Spawn(char ch, vector<vector<int>> zone);
    int Rotate(vector<vector<int>> zone);
    bool Fall(vector<vector<int>>* zone);
    int Left(vector<vector<int>> zone);
    int Right(vector<vector<int>> zone);
    int Stop(vector<vector<int>>* zone);
    vector<vector<int>> Prediction(vector<vector<int>> zone);
    int instantDescent(vector<vector<int>> zone,bool* isShapeSpawned);
};