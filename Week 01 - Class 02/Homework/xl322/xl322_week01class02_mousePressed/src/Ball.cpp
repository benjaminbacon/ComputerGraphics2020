#include "Ball.h"
#include "ofApp.h"
Ball::Ball() {
}

void Ball::setup(float _x, float _y){
	//size, position, and speed	
	xPos = _x;
	yPos = _y;
	radius = ofRandom(10, 50);
	xSpeed = ofRandom(-10, 10);
	ySpeed = ofRandom(-10, 10);
	float theta;
	float frames = 90;
	float stroke;
}

void Ball::update() {
	//angle transforming
	theta += TWO_PI / frames;
	stroke = ofMap(sin(theta), -1, 1, 1, 20);
	//move ball
	xPos += xSpeed;	
	yPos += ySpeed;	
	//border detection
	if (xPos <= radius) {
		xPos = radius;			
		xSpeed = -xSpeed;	
	}
	else if (xPos >= ofGetWidth() - radius) {
		xPos = ofGetWidth() - radius;
		xSpeed = -xSpeed;
	}
	if (yPos <= radius) {
		yPos = radius;
		ySpeed = -ySpeed;
	}
	else if (yPos >= ofGetHeight() - radius) {
		yPos = ofGetHeight() - radius;
		ySpeed = -ySpeed;
	}
}


// draw the ball
void Ball::draw() {

	ofSetColor(0);				// set the GLOBAL color
	ofDrawCircle(xPos, yPos, radius+stroke);		// and draw
}
