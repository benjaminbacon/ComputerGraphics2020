
#pragma once		
#include "ofMain.h"		

class Ball {

public:		

	Ball(int a,int b);				
					

	void update();
	void draw();

	float radius;		// size
	float x, y;			// position
	float dirX, dirY;	// "direction" (a.k.a. velocity or speed)

	ofColor color;

};