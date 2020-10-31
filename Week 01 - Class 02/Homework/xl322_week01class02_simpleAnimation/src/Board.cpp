#include "Board.h"

Board::Board() {
}

void Board::setup(){
	//set the size of the board
	width = ofRandom(40,50);
	length = ofRandom(20,100);

	// set the color of the board
	float R = ofRandom(50, 255);
	float G = ofRandom(50, 255);
	float B = ofRandom(50, 255);
	color = ofColor(R,G,B);

	// set the position of the board
	xPos = ofRandom(0, ofGetWidth() - width);
	yPos = ofRandom(0, ofGetHeight() - length);

	// set the speed of the board
	ySpeed = ofRandom(-10,10);
}

void Board::update() {
	yPos += ySpeed;	
	//border detection
	if (yPos<= 0) {
		yPos = 0;
		ySpeed =-ySpeed;		
	}
	else if (yPos + length >= ofGetHeight()) {
		yPos = ofGetHeight()-length;
		ySpeed =-ySpeed;
	}
}


// draw the ball
void Board::draw() {
	ofRotateY(ofGetFrameNum() % 500);
	ofSetColor(color);			
	ofDrawRectangle(xPos,yPos, width,length);
}
