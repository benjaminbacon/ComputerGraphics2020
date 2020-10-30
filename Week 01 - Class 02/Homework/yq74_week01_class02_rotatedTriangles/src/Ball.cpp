#include "Ball.h"

// constructor
Ball::Ball() {

	// inside the constructor you initialize the object's variables

	// random radius between 10 and 50
	radius = ofRandom(10,50);			

	// random color
	float red	= ofRandom(0,255);
	float green	= ofRandom(0,255);		
	float blue	= ofRandom(0,255);
	color = ofColor(red, green, blue);

	// random position in window
	x = ofRandom(radius, ofGetWidth()  - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	// random x and y speeds/directions between -10 and 10
	dirX = ofRandom(-10,10);
	dirY = ofRandom(-10,10);
}

// update position, etc.
void Ball::update() {
	int numTriangles = 10;
	int minOffset = 5;
	int maxOffset = 70;
	int alpha = 150;
	for (int t = 0; t < numTriangles; ++t) {
		float offsetDistance = ofRandom(minOffset, maxOffset);

		ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());

		// Define a triangle at the origin (0,0) that points to the right
		p1.set(0, 6.25);
		p2.set(25, 0);
		p3.set(0, -6.25);

		float rotation = ofRandom(360); // The rotate function uses degrees!
		p1.rotate(rotation);
		p2.rotate(rotation);
		p3.rotate(rotation);

		ofVec2f triangleOffset(offsetDistance, 0.0);
		triangleOffset.rotate(rotation);

		p1 += mousePos + triangleOffset;
		p2 += mousePos + triangleOffset;
		p3 += mousePos + triangleOffset;
	}
}


	// draw the ball
void Ball::draw() {

		ofSetColor(color);

		ofDrawTriangle(p1, p2, p3);// and draw
}

