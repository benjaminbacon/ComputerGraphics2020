//
//  Ball.cpp
//  rb347_week01class02_ballAnimation
//
//  Created by Rongqi Bei on 2020/10/29.
//

#include "Ball.h"
#include <cmath>

// constructor
Ball::Ball(int ball_category) {
    
    category = ball_category;
    
    if (category == 0){
        r = ofRandom(10, 25);
        float R = ofRandom(0, 255);
        float G = ofRandom(0);
        float B = ofRandom(0, 25);
        float alpha = ofRandom(150, 255);
        color = ofColor(R, G, B, alpha);
        
        x = ofRandom(r, ofGetWidth()/2);
        y = ofRandom(r, ofGetHeight()-r);
        
        Vx = ofRandom(-10, 10);
        Vy = ofRandom(-10, 10);
    }
    if (category == 1){
        r = ofRandom(15, 40);
        float R = ofRandom(0);
        float G = ofRandom(0, 100);
        float B = ofRandom(0, 255);
        float alpha = ofRandom(100, 200);
        color = ofColor(R, G, B, alpha);
        
        x = ofRandom(ofGetWidth()/2, ofGetWidth()-r);
        y = ofRandom(r, ofGetHeight()-r);
        
        Vx = ofRandom(-0.5, 0.5);
        Vy = ofRandom(-0.5, 0.5);
    }
}

// update velocity, position, and motion.
void Ball::update() {
    
    x += Vx;
    y += Vy;
    
    // check boarders
    
    if (category == 0){
        
        if (x <= r){
            Vx = -Vx;
            x = r;
        }
        if (x >= ofGetWidth()/2-r){
            Vx = -Vx;
            x = ofGetWidth()/2-r;
    }
        if (y <= r){
            Vy = -Vy;
            y = r;
        }
        if (y >= ofGetHeight()-r){
            Vy = -Vy;
            y = ofGetHeight()-r;
        }
    }
    
    if (category == 1){
        if (x <= ofGetWidth()/2+r){
            Vx = -Vx;
            x = ofGetWidth()/2+r;
        }
        if (x >= ofGetWidth()-r){
            Vx = -Vx;
            x = ofGetWidth()-r;
    }
        if (y <= r){
            Vy = -Vy;
            y = r;
        }
        if (y >= ofGetHeight()-r){
            Vy = -Vy;
            y = ofGetHeight()-r;
        }
    }
    
}


// draw the ball
void Ball::draw() {

    ofSetColor(color);
    ofDrawCircle(x, y, r);
    update();
    
}

// detect collisions between balls
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


