#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	int numBalls = 5;

	// fill our vector
	for (int i = 0; i < numBalls; i++) {

		Ball tempBall;					// create a temporary ball
		balls.push_back(tempBall);
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	
	for (int i = 0; i < balls.size(); i++) {

		balls[i].update();	
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < balls.size(); i++) {

		balls[i].draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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
	Ball tempBall;					// create a temporary ball
	balls.push_back(tempBall);		// copy the temporary ball into the balls vector
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
