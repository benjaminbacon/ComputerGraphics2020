#include "Ball.h"

// constructor
Ball::Ball() {
    r = ofRandom(15, 40);
    float R = ofRandom(0);
    float G = ofRandom(0);
    float B = ofRandom(0, 255);
    float alpha = ofRandom(100, 200);
    color = ofColor(R, G, B, alpha);
    
    x = ofRandom(ofGetWidth()/2, ofGetWidth()-r);
    y = ofRandom(r, ofGetHeight()-r);
    
    Vx = ofRandom(-0.5, 0.5);
    Vy = ofRandom(-0.5, 0.5);
}

// update position, etc.
void Ball::update() {

    x+=Vx;    // move along x by amount of dirX
    y+=Vy;    // move along y by amount of dirY

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


// draw the ball
void Ball::draw() {

    ofSetColor(color);
    ofDrawCircle(x, y, r);
    update();     
}
