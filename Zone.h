#pragma once
#include <vector>
#include <algorithm>
#include "Globals.h"
using namespace std;
class Zone{
public:
    vector<vector<int>> v;
    Zone(){
        for (int i = 0; i < HEIGHT; i++){
            v.push_back({});
            for (int j = 0; j < WIDTH; j++){
                v[i].push_back(0);
            }
        }
    }
    int Check(){
        int coun = 0;
        vector<int> ind = {};
        for (int i = 0; i < HEIGHT; i++){
            coun = count(v[i].begin(), v[i].end(), 1);
            if (coun == WIDTH){
                ind.push_back(i);
            }
        }
        vector<vector<int>> nv = {};
        for (int i = 0; i < HEIGHT; i++){
            nv.push_back({});
            for (int j = 0; j < WIDTH; j++){
                nv[i].push_back(0);
            }
        }
        int lind = HEIGHT - 1;
        for (int i = HEIGHT - 1; i >= 0; i--){
            if (count(ind.begin(), ind.end(), i) == 0){
                nv[lind] = v[i];
                lind -= 1;
            }
        }
        v = nv;
        return 0;
    }
};