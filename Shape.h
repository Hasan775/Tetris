#pragma once
#include "Globals.h"
#include <vector>
#include "Block.h"
#include <iostream>
using namespace std;
class Shape{
public:
    vector<Block> blocks;
    vector<vector<vector<int>>> rotations;
    char type;
    int rotation;
    Shape(){
        for (int i = 0; i < 4; i++)
        {
            blocks.push_back(Block({0, 0}));
        }
        
    }
    int Spawn(char ch, vector<vector<int>> zone){
        rotations = {};
        rotation = -1;
        type = ch;
        if (ch = 'J' || ch == 'L' || ch == 'S' || ch == 'Z' || ch == 'I'){
            blocks[0].pos = {WIDTH / 2, 1};
        }
        if (ch == 'O' || ch == 'T'){
            blocks[0].pos = {WIDTH / 2, 0};
        }
        if (blocks[0].CheckDirection({0, 0}, zone)){
            return 1;
        }
        Rotate(zone);
        return 0;
    }
    int Rotate(vector<vector<int>> zone){
        rotation += 1;
        vector<vector<int>> nposes = {};
        int x = blocks[0].pos[0];
        int y = blocks[0].pos[1];
        nposes.push_back({x, y});
        if (type == 'J'){
            rotation %= 4;
            if (rotation == 0){
                nposes.push_back({x, y - 1});
                nposes.push_back({x, y + 1});
                nposes.push_back({x - 1, y + 1});
            }
            else if (rotation == 1){
                nposes.push_back({x + 1, y});
                nposes.push_back({x - 1, y});
                nposes.push_back({x - 1, y - 1});
            }
            else if (rotation == 2){
                nposes.push_back({x, y - 1});
                nposes.push_back({x, y + 1});
                nposes.push_back({x + 1, y - 1});
            }
            else{
                nposes.push_back({x + 1, y});
                nposes.push_back({x - 1, y});
                nposes.push_back({x + 1, y + 1});
            }
        }
        if (type == 'L'){
            rotation %= 4;
            if (rotation == 0){
                nposes.push_back({x, y + 1});
                nposes.push_back({x, y - 1});
                nposes.push_back({x - 1, y - 1});
            }
            else if (rotation == 1){
                nposes.push_back({x - 1, y});
                nposes.push_back({x + 1, y});
                nposes.push_back({x + 1, y - 1});
            }
            else if (rotation == 2){
                nposes.push_back({x, y + 1});
                nposes.push_back({x, y - 1});
                nposes.push_back({x + 1, y + 1});
            }
            else{
                nposes.push_back({x - 1, y});
                nposes.push_back({x + 1, y});
                nposes.push_back({x - 1, y + 1});
            }
        }
        if (type == 'O'){
            nposes.push_back({x, y + 1});
            nposes.push_back({x + 1, y});
            nposes.push_back({x + 1, y + 1});
        }
        if (type == 'T'){
            rotation %= 4;
            if (rotation == 0){
                nposes.push_back({x, y + 1});
                nposes.push_back({x, y - 1});
                nposes.push_back({x - 1, y});
            }
            else if (rotation == 1){
                nposes.push_back({x - 1, y});
                nposes.push_back({x + 1, y});
                nposes.push_back({x, y + 1});
            }
            else if (rotation == 2){
                nposes.push_back({x, y + 1});
                nposes.push_back({x, y - 1});
                nposes.push_back({x + 1, y});
            }
            else{
                nposes.push_back({x - 1, y});
                nposes.push_back({x + 1, y});
                nposes.push_back({x, y - 1});
            }
        }
        if (type == 'S'){
            rotation %= 4;
            if (rotation == 0){
                nposes.push_back({x - 1, y});
                nposes.push_back({x, y - 1});
                nposes.push_back({x + 1, y - 1});
            }
            else if (rotation == 1){
                nposes.push_back({x, y - 1});
                nposes.push_back({x + 1, y});
                nposes.push_back({x + 1, y + 1});
            }
            else if (rotation == 2){
                nposes.push_back({x + 1, y});
                nposes.push_back({x, y + 1});
                nposes.push_back({x - 1, y + 1});
            }
            else{
                nposes.push_back({x - 1, y});
                nposes.push_back({x, y + 1});
                nposes.push_back({x - 1, y - 1});
            }
        }
        if (type == 'Z'){
            rotation %= 4;
            if (rotation == 0){
                nposes.push_back({x + 1, y});
                nposes.push_back({x, y - 1});
                nposes.push_back({x - 1, y - 1});
            }
            else if (rotation == 1){
                nposes.push_back({x, y + 1});
                nposes.push_back({x + 1, y});
                nposes.push_back({x + 1, y - 1});
            }
            else if (rotation == 2){
                nposes.push_back({x - 1, y});
                nposes.push_back({x, y + 1});
                nposes.push_back({x + 1, y + 1});
            }
            else{
                nposes.push_back({x - 1, y});
                nposes.push_back({x, y - 1});
                nposes.push_back({x - 1, y + 1});
            }
        }
        if (type == 'I'){
            rotation %= 4;
            if (rotation == 0){
                nposes.push_back({x, y - 1});
                nposes.push_back({x, y + 1});
                nposes.push_back({x, y + 2});
            }
            else if (rotation == 1){
                nposes.push_back({x - 2, y});
                nposes.push_back({x - 1, y});
                nposes.push_back({x + 1, y});
            }
            else if (rotation == 2){
                nposes.push_back({x, y - 2});
                nposes.push_back({x, y - 1});
                nposes.push_back({x, y + 1});
            }
            else{
                nposes.push_back({x - 1, y});
                nposes.push_back({x + 1, y});
                nposes.push_back({x + 2, y});
            }
        }
        for (auto pose : nposes){
            Block bl = Block(pose);
            if (bl.CheckDirection({0, 0}, zone)){
                return 0;
            }
        }
        for (int i = 0; i < 4; i++){
            blocks[i].pos = nposes[i];
        }
        return 0;
    }
    bool Fall(vector<vector<int>>* zone){
        for (auto i : blocks){
            if (i.CheckDirection({0, 1}, *zone)){
                Stop(zone);
                return false;
            }
        }
        for (int i = 0; i < blocks.size(); i++){
            blocks[i].pos = {blocks[i].pos[0], blocks[i].pos[1] + 1};
        }
        return true;
    }
    int Left(vector<vector<int>> zone){
        for (auto i : blocks){
            if (i.CheckDirection({-1, 0}, zone)){
                return 0;
            }
        }
        for (int i = 0; i < 4; i++){
            blocks[i].pos = {blocks[i].pos[0] - 1, blocks[i].pos[1]};
        }
        return 0;
    }
    int Right(vector<vector<int>> zone){
        for (auto i : blocks){
            if (i.CheckDirection({1, 0}, zone)){
                return 0;
            }
        }
        for (int i = 0; i < 4; i++){
            blocks[i].pos = {blocks[i].pos[0] + 1, blocks[i].pos[1]};
        }
        return 0;
    }
    int Stop(vector<vector<int>>* zone){
        for (int i = 0; i < blocks.size(); i++){
            zone->at(blocks[i].pos[1])[blocks[i].pos[0]] = 1;
        }
        return 0;
    }
    vector<vector<int>> Prediction(vector<vector<int>> zone){
        vector<vector<int>> ret = {};
        for (int i = 0; i < HEIGHT; i++){
            for (int j = 0; j < 4; j++){
                if (blocks[j].CheckDirection({0, i}, zone)){
                    if (i == 0){
                        return {};
                    }
                    for (int k = 0; k < 4; k++)
                    {
                        ret.push_back({blocks[k].pos[0], blocks[k].pos[1] + i - 1});
                    }
                    return ret;
                }
            }
        }
        return {};
    }
    int instantDescent(vector<vector<int>> zone,bool* isShapeSpawned){
        *isShapeSpawned = false;
        auto npos = Prediction(zone);
        for (int i = 0; i < 4; i++){
            blocks[i].pos = npos[i];
        }
    }
};