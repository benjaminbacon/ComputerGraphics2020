#include "ofApp.h"
#include "math.h"
int bgColor = 0;
int nextTriggerChangingBallColor = 0;
int nextTriggerChangingBgColor = 0;
int bgChangingDir = 1;
int currentBallNum = 0;
int colorChangingInterval = 10;
//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(bgColor);

	int numBalls = 8;

	for (int i = 0; i < numBalls; i++) {
		Ball tempBall;
		balls.push_back(tempBall);
		currentBallNum++;
	}
	// there's actually a bug, if two balls randomly spawn as two overlapped circles,
	// they will shake with each other

	// i tried to fix this bug using code below that was commented out,
	// but i might made some mistakes

	//Ball tempBall;
	//balls.push_back(tempBall);

	//for (int i = 0; i < numBalls; i++) {		// loop 30 times

	//	Ball tempBall;					// create a temporary ball
	//	for (int j = 0; j < balls.size(); j++) {
	//		if (pow(tempBall.x - balls[j].x, 2) + pow(tempBall.y - balls[j].y, 2)
	//			> pow(tempBall.radius + balls[j].radius, 2)) {

	//			// only when two balls now overlap, push into the vector
	//			balls.push_back(tempBall);		// copy the temporary ball into the balls vector
	//											// (push_back() adds the ball to the end of the vector, increasing the vector's size by 1)
	//		}
	//	}
		
	//}
	
}


//--------------------------------------------------------------
void ofApp::update(){

	// update with ball collision
	for (int i = 0; i < balls.size() - 1; i++) {
		for (int j = i + 1; j < balls.size(); j++) {
			if (pow(balls[i].x - balls[j].x, 2) + pow(balls[i].y - balls[j].y, 2)
				< pow(balls[i].radius + balls[j].radius, 2) + 1) {
				// haven't figure it out how to deal with the collision,
				// i've tried to use ==, but it doesn't work successfully,
				// so I add a "< 1" to it
				// and sometimes two balls will collide forever untill a third ball collides with them
				balls[i].collide();
				balls[j].collide();
			}
		}
	}

	// update each ball in our vector
	for (int i = 0; i < balls.size(); i++) {	// one way to loop through a whole vector
		balls[i].update();	// we can access an individual ball by its "index" number in the vector
							// e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
									// (note that vectors always start at 0, not 1!!)
	}



	// i learned this way of changing color every certain time interval from here:
	// https://forum.openframeworks.cc/t/triggering-a-function-or-event-only-once-at-a-certain-hour-c-question/6169
	int nowTime = ofGetElapsedTimeMillis();
	if (nowTime > nextTriggerChangingBallColor) {
		// change color of the ball
		for (int i = 0; i < balls.size(); i++) {
			balls[i].color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
		}

		nextTriggerChangingBallColor = nowTime + colorChangingInterval;

		
	}

	if (nowTime > nextTriggerChangingBgColor) {
		// change color of the background, smoothly

		// if turning white
		if (bgChangingDir > 0) {
			if (bgColor < 255) {
				ofBackground(bgColor);
				bgColor += 1;
			}
			else {
				// to the black
				bgChangingDir = - bgChangingDir;
			}
		}
		// if turning black
		else {
			if (bgColor > 0) {
				ofBackground(bgColor);
				bgColor -= 1;
			}
			else {
				// to the white
				bgChangingDir = - bgChangingDir;
			}
		}
		// every 10 milliseconds
		nextTriggerChangingBgColor = nowTime + 10;

	}



}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < balls.size(); i++) {

		balls[i].draw();
	}

	ofDrawBitmapString("Left Mouse: add ball\nRight Mouse: delete ball\n-: decrease interval\n=: increase interval", 10, 20);

	ofDrawBitmapString("The color changing interval is: " + ofToString(colorChangingInterval) + "ms", 10, 80);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '-' and colorChangingInterval > 0) {
		colorChangingInterval -= 10;
	}

	if (key == '=') {
		colorChangingInterval += 10;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) {
		Ball tempBall;
		tempBall.x = x;
		tempBall.y = y;
		balls.push_back(tempBall);
		currentBallNum++;
	}
	if (button == 2 and currentBallNum > 1) {
		balls.pop_back();
		currentBallNum--;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
