#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundAuto(true); 

	ofBackground(0);


	
}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < groupOfBalls.size(); i++) {
		groupOfBalls[i].update();
	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawBitmapString("left button of mouse to add a ball, right button to erase a ball", 10, ofGetHeight() - 30);
	for (int i = 0; i < groupOfBalls.size(); i++) {
		groupOfBalls[i].draw();
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
void ofApp::mouseDragged(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)//left button of mouse to add a ball, right button to erase a ball
{
	
	if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) 
	{
		Ball tempBall;
		groupOfBalls.push_back(tempBall);
	}

	if (ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT))
	{
		if (groupOfBalls.size() != 0)//avoid operating on an empty vector
			groupOfBalls.erase(groupOfBalls.begin());
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
	groupOfBalls.clear();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
