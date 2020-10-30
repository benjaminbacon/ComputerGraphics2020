//
//  Ball.cpp
//  rb347_week01class02_fourBallsWorld
//
//  Created by Rongqi Bei on 2020/10/29.
//

#include "Ball.h"
#include <cmath>

int world_height = 400;

// constructor
Ball::Ball(int ball_category, int ball_create_by_user, int ball_color_by_user) {
    
    category = ball_category;
    create_by_user = ball_create_by_user;
    color_by_user = ball_color_by_user;
    
    if (category == 1){
        r = ofRandom(15, 25);
        
        float R = ofRandom(253, 255);
        float G = ofRandom(218, 248);
        float B = ofRandom(173, 220);
        float alpha = ofRandom(200, 255);
        color = ofColor(R, G, B, alpha);
        
        Vx = ofRandom(-3, 3);
        Vy = ofRandom(-3, 3);
        
        if (create_by_user == 0){
            x = ofRandom(r, ofGetWidth()/4-r);
            y = ofRandom(r, world_height-r);
        }
        else{
            x = ofGetMouseX();
            y = ofGetMouseY();
        }
    }
    if (category == 2){
        r = ofRandom(30, 35);
        
        float R = ofRandom(0, 100);
        float G = ofRandom(130, 200);
        float B = ofRandom(205, 255);
        float alpha = ofRandom(100, 200);
        color = ofColor(R, G, B, alpha);
        
        Vx = ofRandom(-0.5, 0.5);
        Vy = ofRandom(-0.5, 0.5);
        
        if (create_by_user == 0){
            x = ofRandom(ofGetWidth()/4+r, ofGetWidth()/2-r);
            y = ofRandom(r, world_height-r);
        }
        else{
            x = ofGetMouseX();
            y = ofGetMouseY();
        }
    }
    if (category == 3){
        r = ofRandom(10, 15);
        
        float R = ofRandom(210, 255);
        float G = ofRandom(25, 50);
        float B = ofRandom(25, 55);
        float alpha = ofRandom(100, 200);
        color = ofColor(R, G, B, alpha);
        
        Vx = ofRandom(-5, 5);
        Vy = ofRandom(-5, 5);
        
        if (create_by_user == 0){
            x = ofRandom(ofGetWidth()/2+r, ofGetWidth()*3/4-r);
            y = ofRandom(r, world_height-r);
        }
        else{
            x = ofGetMouseX();
            y = ofGetMouseY();
        }
    }
    if (category == 4){
        r = ofRandom(15, 30);
        
        float R = ofRandom(70, 140);
        float G = ofRandom(200, 255);
        float B = ofRandom(0, 70);
        float alpha = ofRandom(100, 200);
        color = ofColor(R, G, B, alpha);
        
        Vx = ofRandom(-3, 3);
        Vy = ofRandom(-3, 3);
        
        if (create_by_user == 0){
            x = ofRandom(ofGetWidth()*3/4+r, ofGetWidth()-r);
            y = ofRandom(r, world_height-r);
        }
        else{
            x = ofGetMouseX();
            y = ofGetMouseY();
        }
    }
    
    if (color_by_user != 0){
        if (color_by_user == 1){
            color = ofColor(ofRandom(253, 255), ofRandom(218, 248), ofRandom(173, 220), ofRandom(200, 255));
            Vx = ofRandom(-3, 3);
            Vy = ofRandom(-3, 3);
            r = ofRandom(15, 25);
        }
        if (color_by_user == 2){
            color = ofColor(ofRandom(0, 100), ofRandom(130, 200), ofRandom(205, 255), ofRandom(100, 200));
            Vx = ofRandom(-0.5, 0.5);
            Vy = ofRandom(-0.5, 0.5);
            r = ofRandom(30, 35);
        }
        if (color_by_user == 3){
            color = ofColor(ofRandom(210, 255), ofRandom(25, 50),ofRandom(25, 55), ofRandom(100, 200));
            Vx = ofRandom(-5, 5);
            Vy = ofRandom(-5, 5);
            r = ofRandom(10, 15);
        }
        if (color_by_user == 4){
            color = ofColor(ofRandom(70, 140), ofRandom(200, 255), ofRandom(0, 70), ofRandom(100, 200));
            Vx = ofRandom(-3, 3);
            Vy = ofRandom(-3, 3);
            r = ofRandom(15, 30);
        }
    }
    
}





// update position, etc.
void Ball::update() {
    
    x += Vx;
    y += Vy;
    
    // check boarders
    
    if (category == 1){
        
        if (x <= r){
            Vx = -Vx;
            x = r;
        }
        if (x >= ofGetWidth()/4-r){
            Vx = -Vx;
            x = ofGetWidth()/4-r;
    }
        if (y <= r){
            Vy = -Vy;
            y = r;
        }
        if (y >= world_height-r){
            Vy = -Vy;
            y = world_height-r;
        }
    }
    
    if (category == 2){
        if (x <= ofGetWidth()/4+r){
            Vx = -Vx;
            x = ofGetWidth()/4+r;
        }
        if (x >= ofGetWidth()/2-r){
            Vx = -Vx;
            x = ofGetWidth()/2-r;
    }
        if (y <= r){
            Vy = -Vy;
            y = r;
        }
        if (y >= world_height-r){
            Vy = -Vy;
            y = world_height-r;
        }
    }
    
    if (category == 3){
        if (x <= ofGetWidth()/2+r){
            Vx = -Vx;
            x = ofGetWidth()/2+r;
        }
        if (x >= ofGetWidth()*3/4-r){
            Vx = -Vx;
            x = ofGetWidth()*3/4-r;
    }
        if (y <= r){
            Vy = -Vy;
            y = r;
        }
        if (y >= world_height-r){
            Vy = -Vy;
            y = world_height-r;
        }
    }
    if (category == 4){
        if (x <= ofGetWidth()*3/4+r){
            Vx = -Vx;
            x = ofGetWidth()*3/4+r;
        }
        if (x >= ofGetWidth()-r){
            Vx = -Vx;
            x = ofGetWidth()-r;
    }
        if (y <= r){
            Vy = -Vy;
            y = r;
        }
        if (y >= world_height-r){
            Vy = -Vy;
            y = world_height-r;
        }
    }
    
}


// draw the ball
void Ball::draw() {
    
    ofSetColor(color);
    ofDrawCircle(x, y, r);
    update();

}

void Ball::collision(Ball b){
    
    float dist = sqrt(pow(x-b.x,2)+pow(y-b.y,2));
    if (dist <= r + b.r){
        
        float angle = atan2(abs(b.y-y), abs(b.x-x));
        float vx1 = cos(angle)*Vx + sin(angle)*Vy;
        float vy1 = sin(angle)*-Vx + cos(angle)*Vy;
        float vx2 = cos(angle)*b.Vx + sin(angle)*b.Vy;
        float vy2 = sin(angle)*-b.Vx + cos(angle)*b.Vy;
        
        float m1 = r*r*r;
        float m2 = b.r*b.r*b.r;
        float vx1final = ((m1 - m2)*vx1 + 2*m2*vx2)/(m1 + m2);
        float vx2final = ((m2 - m1)*vx2 + 2*m1*vx1)/(m1 + m2);
        
        Vx = vx1final*cos(angle) - vy1*sin(angle);
        Vy = vx1final*sin(angle) + vy1*cos(angle);
        b.Vx = cos(angle)*vx2final - sin(angle)*vy2;
        b.Vy = sin(angle)*vx2final + cos(angle)*vy2;
        
        float overlap = r + b.r - dist;
        if (x<=b.x){
            x -= overlap/2;
            b.x += overlap/2;
        }
        else{
            x += overlap/2;
            b.x -= overlap/2;
        }
    }
    
}
