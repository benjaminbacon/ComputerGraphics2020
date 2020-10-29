//
//  Pipe.cpp
//  zs93_week1class2
//
//  Created by Zeyu Shen on 10/29/20.
//

#include "Pipe.hpp"

Pipe::Pipe(){
    width = 20;
    color = ofColor(100);
    
    upper = ofRandom(100, ofGetHeight()-100);
    lower = upper-100;
    X = ofGetWidth()-width;
}

void Pipe::update(){
    X-=dirX;
}

void Pipe::draw(){
    ofSetColor(color);
    double h_upper = ofGetHeight()-upper;
    double h_lower = lower;
    ofDrawRectangle(X, upper, width, h_upper);
    ofDrawRectangle(X, 0, width, h_lower);
}
