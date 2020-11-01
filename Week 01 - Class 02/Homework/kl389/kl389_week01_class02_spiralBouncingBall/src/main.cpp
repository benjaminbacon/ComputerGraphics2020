#include "ofMain.h"
#include "ofApp.h"

//========================================================================
/*
Note;
This version of bouncing Ball is to make a sence of balls bouncing not only in the flat screen but bouncing in 3 dimension.
it seems like the balls moving in a vortex.
Suggest adjust the ball number beyond 15 to reach the best visual experience.

Click can add a ball and press the keyboard can delete a ball.
The number of ball is on the terminal.
*/



int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
