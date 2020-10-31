#include "Ball.h"
#include <stdlib.h>

using namespace std;


// constructor
Ball::Ball() {

	// inside the constructor you initialize the object's variables

	// random radius between 10 and 40
	radius = ofRandom(10,30);			

	// random color
	float red	= ofRandom(30,165);
	float green	= ofRandom(30,215);		
	float blue	= ofRandom(125,255);
	color = ofColor(red, green, blue);

	// random position in window
	x = ofRandom(radius, ofGetWidth()  - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	// random x and y speeds/directions between -10 and 10
	dirX = ofRandom(-10, -5);
	dirY = ofRandom(-1,0);
}

// update position, etc.
void Ball::update() {

	x+=dirX;	// move along x by amount of dirX
	y+=dirY;	// move along y by amount of dirY

	
	//adjust the size of the ball
	float prop;
	float temp = 0.012;
	
	if (dirX > 0 && x < 512)
		prop = -temp;
	else if (dirX > 0 && x > 512)
		prop = temp;
	else if (dirX < 0 && x>512)
		prop = temp;
	else
		prop = -temp;

	radius += radius*prop;
	

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