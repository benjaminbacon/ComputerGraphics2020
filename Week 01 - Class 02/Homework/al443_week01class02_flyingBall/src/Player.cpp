#include "Player.h"

Player::Player(int a, int b,int c)
{
	edge = ofRandom(60, 75);

	float red = ofRandom(0, 255);
	float green = ofRandom(0, 255);
	float blue = ofRandom(0, 255);
	color = ofColor(red, green, blue);

	x = a;
	y = b;
	v = c;
}

bool Player::Collide(Ball a)
{
	double dis = sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	if (dis < edge + a.radius-13) return 1; 
	else return 0;
}

void Player::update()
{
	
}

void Player::draw() {

	ofSetColor(color);				// set the GLOBAL color
	ofDrawRectangle(x, y, edge, edge);		// and draw
}
