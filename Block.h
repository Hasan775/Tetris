#pragma once
#include "Zone.h"
#include "Globals.h"
#include <vector>
using namespace std;
class Block{
public:
    vector<int> pos;
    Block(vector<int> coor){
        pos = coor;
    }
    int GoDown(){
        pos = {pos[0], pos[1] - 1};
        return 0;
    }
    int GoLeft(){
        pos = {pos[0] - 1, pos[1]};
        return 0;
    }
    int GoRight(){
        pos = {pos[0] + 1, pos[1]};
        return 0;
    }
    bool CheckDirection(vector<int> direction, vector<vector<int>> zone){
        if (pos[0] + direction[0] == -1 || pos[0] + direction[0] == WIDTH || pos[1] + direction[1] == HEIGHT){
            return true;
        }
        if (zone[pos[1] + direction[1]][pos[0] + direction[0]] == 1){
            return true;
        }
        return false;
    }
};