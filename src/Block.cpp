#include "../headers/Globals.h"
#include "../headers/Block.h"
#include <vector>
using namespace std;
Block::Block(vector<int> coor){
    pos = coor;
}
int Block::GoDown(){
    pos = {pos[0], pos[1] - 1};
    return 0;
}
int Block::GoLeft(){
    pos = {pos[0] - 1, pos[1]};
    return 0;
}
int Block::GoRight(){
    pos = {pos[0] + 1, pos[1]};
    return 0;
}
bool Block::CheckDirection(vector<int> direction, vector<vector<int>> zone){
    if (pos[0] + direction[0] == -1 || pos[0] + direction[0] == WIDTH || pos[1] + direction[1] == HEIGHT){
        return true;
    }
    if (zone[pos[1] + direction[1]][pos[0] + direction[0]] == 1){
        return true;
    }
    return false;
}