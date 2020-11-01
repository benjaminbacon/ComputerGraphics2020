#include "Ball.h"


Ball::Ball() {

	

	
	radius = 50;

	// random color
	float red	= ofRandom(0,255);
	float green	= ofRandom(0,255);		
	float blue	= ofRandom(0,255);
	color = ofColor(red, green, blue);

	// random position in window
	x = ofRandom(radius, ofGetWidth()  - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	// random x and y speeds/directions between -10 and 10
	dirX = ofRandom(-20,20);
	dirY = ofRandom(-20,20);
}

void Ball::update() {

	//where the ball go
	x += dirX;
	y += dirY;



}


// draw the ball
void Ball::draw() {

	ofRotateZ(ofGetFrameNum() % 1000);
	ofRotateX(ofGetFrameNum() % 1000);
	ofRotateY(ofGetFrameNum() % 360);
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
	ofSetColor(color + 50);
	ofDrawTriangle(x - 35.355, y - 35.355, x + 35.355, y - 35.355, x, y + 35.355);
}

