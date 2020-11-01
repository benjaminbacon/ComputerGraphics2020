#pragma once
#include "ofMain.h"
#include "Ball.h"
class Player{
public:

	Player(int a, int b,int c);
	bool Collide(Ball a);

	void update();
	void draw();

	float x, y,v;			// position
	float edge;

	ofColor color;
};

