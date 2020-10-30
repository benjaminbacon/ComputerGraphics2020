//
//  Ball.h
//  zg73_week01class02_bouncingball
//
//  Created by Bob G on 2020/10/29.
//

#pragma once
#include "ofMain.h"


class Ball{
    
public:
    Ball(int x1,int y1,int player);
    void update();
    void draw();
    void same(Ball a);
    void crash(Ball a);
    
    float r;
    float x,y;
    float Vx,Vy;
    float play;

    ofColor color;
    

};
