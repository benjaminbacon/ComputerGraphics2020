#ifndef _BALL
#define _BALL
#include "ofMain.h"		
#include "ofApp.h"	
class Ball {
	public:							
	void setup(float _x, float _y);
	void update();
	void draw();
	float radius, xPos, yPos, xSpeed, ySpeed;	
	float theta, stroke, frames;
	Ball();
	private:
};
#endif