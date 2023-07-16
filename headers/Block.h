#pragma once
#include <vector>
using namespace std;
class Block{
public:
    vector<int> pos;
    Block(vector<int> coor);
    int GoDown();
    int GoLeft();
    int GoRight();
    bool CheckDirection(vector<int> direction, vector<vector<int>> zone);
};