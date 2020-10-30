//
//  flower.cpp
//  tw229_dkuOF_2020_w1c02hw01
//
//  Created by 吴桐 on 10/30/20.
//

#include "Flower.hpp"


Flower::Flower(){
    
    radius=ofRandom(16, 32);
    x = ofRandom(24, ofGetWidth()  - 24);
    y = ofRandom(24, ofGetHeight() - 24);
    
    dirX = ofRandom(-5,5);
    dirY = ofRandom(-5,5);
}
void Flower::update(){
    
    colorcenter = ofColor(r, g, b);
    colorpetal = ofColor(r+20, g+20, b+20);
    colorheart = ofColor(r+10, g+10, b+10);
    x+=dirX;
    y+=dirY;

    if (x <=radius) {
        x = radius;            // set the position back to the edge of window
        dirX = -dirX;        // and reverse direction
       r = ofRandom(160,215);
      g    = ofRandom(200,225);
       b    = ofRandom(160,210);
        radius=ofRandom(16, 32);
    }
    // check right
    else if (x >= ofGetWidth() - radius) {
        x = ofGetWidth() - radius;            // similar to above
        dirX = -dirX;
        r = ofRandom(150,235);
       g    = ofRandom(170,215);
        b    = ofRandom(130,220);
        radius=ofRandom(16, 32);
    }
    if (y <= radius) {
        y = radius;
        dirY = -dirY;
        r = ofRandom(180,235);
       g    = ofRandom(170,225);
        b    = ofRandom(160,210);
        radius=ofRandom(16, 32);
    }
    else if (y >= ofGetHeight() - radius) {
        y = ofGetHeight() - radius;
        dirY = -dirY;
        r = ofRandom(140,235);
       g    = ofRandom(210,225);
        b    = ofRandom(150,180);
        radius=ofRandom(16, 32);
    }

}

void Flower::draw() {
    theta += TWO_PI/frames;
    ofSetColor(colorpetal);
    

    ofDrawCircle(x+radius, y, radius);
    ofDrawCircle(x-radius, y, radius);
    ofDrawCircle(x, y+radius, radius);
    ofDrawCircle(x, y-radius, radius);
    ofSetColor(colorcenter);
    ofDrawCircle(x,y, radius+4*sin(theta));
    ofSetColor(colorheart);
    ofDrawCircle(x,y, 4+4*cos(theta));

}

