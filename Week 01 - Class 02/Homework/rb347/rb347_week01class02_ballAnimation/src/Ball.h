//
//  Ball.h
//  rb347_week01class02_ballAnimation
//
//  Created by Rongqi Bei on 2020/10/29.
//

#pragma once
#include "ofMain.h"

class Ball {

public:

    Ball(int ball_category);
                
       
    void set_category();
    void update();
    void draw();
    void collision(Ball b);

    float r;
    float x, y;
    float Vx, Vy;
    
    ofColor color;
    
private:
    int category;

};

