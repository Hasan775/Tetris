#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <chrono>
#include "../headers/Zone.h"
#include "../headers/Shape.h"
#include "../headers/Globals.h"
#include "../headers/Block.h"
using namespace std;
using namespace std::chrono;
int DrawFrame(Zone zone, Shape shape, char holding, char next){
    vector<vector<char>> v;
    system("cls");
    for (int i = 0; i < WIDTH; i++){
        cout<<"_";
    }
    cout<<"\n";
    for (int i = 0; i < HEIGHT; i++)
    {
        v.push_back({});
        for (int j = 0; j < WIDTH; j++){
            v[i].push_back(' ');
        }
    }
    vector<vector<int>> predicted = shape.Prediction(zone.v);
    for (auto pred : predicted)
    {
        v[pred[1]][pred[0]] = '+';
    }
    for (auto bl : shape.blocks){
        v[bl.pos[1]][bl.pos[0]] = '#';
    }
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (zone.v[i][j] == 1){
                v[i][j] = '#';
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j <WIDTH; j++){
            cout<<v[i][j];
        }
        cout<<"\n";
    }
    for (int i = 0; i < WIDTH; i++){
       cout<<"*";
    }
    cout<<"\n\n\nHolded: "<<holding;
    cout<<"\n\nNext: "<<next;
    return 0;
}
int main(){
    Zone zone = Zone();
    Shape shape = Shape();
    vector<char> blocks = {'J', 'L', 'O', 'T', 'S', 'Z', 'I'};
    char holded = ' ';
    srand(time(0));
    int code = 0, block = 0, blockn = 0;
    blockn = rand() % blocks.size();
    bool isShapeSpawned = false, isRotationPressed = false, isHoldingUsed;
    unsigned long diff = 0, fdiff = 0;
    auto lastClock = high_resolution_clock::now().time_since_epoch().count();
    auto newClock = high_resolution_clock::now().time_since_epoch().count();
    while (true){
        lastClock = newClock;
        newClock = high_resolution_clock::now().time_since_epoch().count();
        diff += newClock - lastClock;
        fdiff += newClock - lastClock;
        if (!isShapeSpawned){
            isShapeSpawned = true;
            isHoldingUsed = false;
            srand(time(0));
            block = blockn;
            blockn = rand() % blocks.size();
            zone.Check();
            code = shape.Spawn(blocks[block], zone.v);
            if (code == 1){
                cout<<"\nYou Lost";
                getch();
                return 0;
            }
        }
        if (diff >= 0.5 * CHRONOSECOND)
        {
            isShapeSpawned = shape.Fall(&zone.v);
            diff -= 0.5 * CHRONOSECOND;
        }
        if (kbhit()){
            code = getch();
            if (code == 119){
                shape.Rotate(zone.v);
            }
            if (code == 97){
                shape.Left(zone.v);
            }
            if (code == 100){
                shape.Right(zone.v);
            }
            if (code == 115){
                shape.instantDescent(zone.v, &isShapeSpawned);
                shape.Stop(&zone.v);
            }
            if (code == 99 && !isHoldingUsed){
                isHoldingUsed = true;
                if (holded == ' '){
                    holded = shape.type;
                    srand(time(0));
                    block = rand() % blocks.size();
                    zone.Check();
                    shape.Spawn(blocks[block], zone.v);
                }
                else{
                    char nh = holded;
                    holded = shape.type;
                    shape.Spawn(nh, zone.v);
                }
            }
            DrawFrame(zone, shape, holded, blocks[blockn]);
        }
        if (fdiff >= 0.5 * CHRONOSECOND)
        {
            DrawFrame(zone, shape, holded, blocks[blockn]);
            fdiff -= 0.5 * CHRONOSECOND;
        }
    }
}