#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
	int cnt = 20;
	for (int i = 0; i < cnt; i++) {

		Ball ball;
		balls.push_back(ball);
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	// update each ball in our vector
	for (int i = 0; i < balls.size(); i++) {	// one way to loop through a whole vector

		balls[i].update();	// we can access an individual ball by its "index" number in the vector
							// e.g. balls[0] is the first ball in the vector, balls[1] is the second ball, etc.
							// (note that vectors always start at 0, not 1!!)
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
