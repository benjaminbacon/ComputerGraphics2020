#include "Ball.h"

// constructor
Ball::Ball() {
	// inside the constructor you initialize the object's variables
}

void Ball::setup() {

	state = false;

	x = ofRandom(dim, ofGetWidth() - dim);
	y = ofRandom(dim, ofGetHeight() - dim);

	speedX = ofRandom(-10, 10);           
	speedY = ofRandom(-10, 10);

	BALLSIZE = 20; 
	dim = BALLSIZE; //Size would be 20

	// random color
	float red = ofRandom(0, 255);
	float green = ofRandom(0, 255);
	float blue = ofRandom(0, 255);
	color = ofColor(red, green, blue);

}


// update position, etc.
void Ball::update() {

	//the ball will follow your click
	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
		x = ofGetMouseX();
		y = ofGetMouseY();
		speedX = ofRandom(-10, 10);          
		speedY = ofRandom(-10, 10);
	}

	x += speedX;	// move along x by amount of dirX
	y += speedY;	// move along y by amount of dirY

	// check for bounces at edges of window:

	// check left
	if (x <= max(dim,BALLSIZE - dim)) {
		x = max(dim, BALLSIZE - dim);			// set the position back to the edge of window
		speedX = -speedX;		// and reverse direction
		state = !state;        // change state
	}
	// check right
	else if (x >= ofGetWidth() - max(dim, BALLSIZE - dim)) {
		x = ofGetWidth() - max(dim, BALLSIZE - dim);			// similar to above
		speedX = -speedX;
		state = !state;        // change state
	}

	// check top and bottom
	if (y <= max(dim, BALLSIZE - dim)) {
		y = max(dim, BALLSIZE - dim);
		speedY = -speedY;
		state = !state;        // change state
	}
	else if (y >= ofGetHeight() - max(dim, BALLSIZE - dim)) {
		y = ofGetHeight() - max(dim, BALLSIZE - dim);
		speedY = -speedY;
		state = !state;        // change state
	}
}


// draw the ball
void Ball::draw() {
	if (dim != BALLSIZE && !state) {
		dim++;
	}
	else if (dim != 0 && state) {
		dim--;
	}

	ofSetColor(color);				// set the GLOBAL color
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawCircle(x, y, dim);		// and draw sphere
	ofDrawRectangle(x, y, (BALLSIZE - dim)*2, (BALLSIZE - dim)*2); //and draw rectangle
}
