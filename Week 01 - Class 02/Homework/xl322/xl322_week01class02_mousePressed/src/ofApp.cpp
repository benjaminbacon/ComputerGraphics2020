#include "ofApp.h"
//--------------------------------------------------------------

void ofApp::setup(){
	ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){	
	for (int i = 0; i < BallArray.size(); i++) {
		BallArray[i].update();		
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < BallArray.size(); i++) {
		BallArray[i].draw();
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
	Ball ball;
	ball.setup(x, y);
	BallArray.push_back(ball);

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
