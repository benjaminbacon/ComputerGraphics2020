//
//  Ball.cpp
//  zg73_week01class02_bouncingball
//
//  Created by Bob G on 2020/10/29.
//

#include "Ball.h"
Ball::Ball(){
    r = ofRandom(10,25);
    float red = ofRandom(0,255);
    float green = ofRandom(0,255);
    float blue = ofRandom(0,255);

    color = ofColor(red,green,blue);
    
    x = ofRandom(r,ofGetWidth());
    y = ofRandom(r,ofGetHeight()-r);
    
    Vx = ofRandom(-5,5);
    Vy = ofRandom(-5,5);
}

void Ball::update(){
    x += Vx;
    y += Vy;
    
    if (x <= r){
        Vx = -Vx;
        x = r;
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

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(x,y,r);
    update();
}

void Ball::same(Ball a){
    float distance = sqrt(pow(x-a.x,2)+pow(y-a.y,2));
    if(distance<=r+a.r){
        if(r<a.r){
            color = a.color;
        }else{
            a.color = color;
        }
    }
}

void Ball::crash(Ball a){
    
    float distance = sqrt(pow(x-a.x,2)+pow(y-a.y,2));
    if (distance <= r+a.r){
        
        float angle = atan2(abs(a.y-y),abs(a.x-x));
        float vx = cos(angle)*Vx+sin(angle)*Vy;
        float vy = sin(angle)*Vx+cos(angle)*Vy;
        float vax = cos(angle)*a.Vx+sin(angle)*a.Vy;
        float vay = sin(angle)*a.Vx+cos(angle)*a.Vy;
        
        float m1 = r*r*r;
        float m2 = a.r*a.r*a.r;
        float v = ((m1-m2)*vx+2*m2*vax)/(m1+m2);
        float va = ((m2-m1)*vax+2*m1*vx)/(m1+m2);
        
        Vx = v*cos(angle)-vy*sin(angle);
        Vy = v*sin(angle)+vy*cos(angle);
        a.Vx = cos(angle)*va-sin(angle)*vay;
        a.Vy = sin(angle)*va+cos(angle)*vay;
        
        distance = r+a.r-distance;
        if (x<=a.x){
            x -= 3*distance/4;
            a.x += 3*distance/4;
        }
        else{
            x += 3*distance/4;
            a.x -= 3*distance/4;
        }
    }
    
}




