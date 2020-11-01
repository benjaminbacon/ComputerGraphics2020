#include "Ball.h"


Ball::Ball(int a,int b){

	radius = ofRandom(25, 35);

	float red = ofRandom(0, 255);
	float green = ofRandom(0, 255);
	float blue = ofRandom(0, 255);
	color = ofColor(red, green, blue);

	x = a;
	y = b;

	dirX = ofRandom(-10, 10);
	dirY = ofRandom(-10, 10);
}

void Ball::update() {

	x += dirX;	
	y += dirY;	

	if (x <= radius) {
		x = radius;			
		dirX = -dirX;		
	}

	else if (x >= ofGetWidth() - radius) {
		x = ofGetWidth() - radius;			
		dirX = -dirX;
	}

	if (y <= radius) {
		y = radius;
		dirY = -dirY;
	}
	else if (y >= ofGetHeight() - radius) {
		y = ofGetHeight() - radius;
		dirY = -dirY;
	}
}


// draw the ball
void Ball::draw() {

	ofSetColor(color);				// set the GLOBAL color
	ofDrawCircle(x, y, radius);		// and draw
}
