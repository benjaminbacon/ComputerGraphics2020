#include "Ball.h"

// constructor
Ball::Ball() {

	// inside the constructor you initialize the object's variables

	// random radius between 10 and 50
	radius = ofRandom(10,50);			

	int cnt = 0;
	// random color
	float red	= ofRandom(0,255);
	float green	= ofRandom(0,255);		
	float blue	= ofRandom(0,255);
	color = ofColor(red, green, blue);

	// random position in window
	x = ofRandom(radius, ofGetWidth()  - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	// random x and y speeds/directions between -10 and 10
	dirX = ofRandom(-3,3);
	dirY = ofRandom(-3,3);
}

// update position, etc.
void Ball::update() {

	cnt+=2;
	if (cnt == 10)
	{
		color = ofColor(255, 0, 0);
	}
	if (cnt == 20)
	{
		color = ofColor(255, 165, 0);
	}
	if (cnt == 30)
	{
		color = ofColor(255, 255, 0);
	}
	if (cnt == 40)
	{
		color = ofColor(0, 255, 0);
	}
	if (cnt == 50)
	{
		color = ofColor(0, 127, 255);
	}
	if (cnt == 60)
	{
		color = ofColor(0, 0, 255);
	}
	if (cnt == 70)
	{
		cnt = 0;
		color = ofColor(139, 0, 255);
	}
	x+=dirX;	// move along x by amount of dirX
	y+=dirY;	// move along y by amount of dirY

	// check for bounces at edges of window:

	// check left
	if (x <= radius) {
		x = radius;			// set the position back to the edge of window
		dirX = -dirX;		// and reverse direction
	}
	// check right
	else if (x >= ofGetWidth() - radius) {
		x = ofGetWidth() - radius;			// similar to above
		dirX = -dirX;
	}

	// check top and bottom
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
	ofDrawCircle(x,y, radius);		// and draw
}