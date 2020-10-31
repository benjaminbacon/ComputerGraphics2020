#pragma once		
#include "ofMain.h"	

class Board {

public:	
	void setup();
	void update();
	void draw();
	float width,length,xPos,yPos,ySpeed;
	ofColor color;
	Board();
};