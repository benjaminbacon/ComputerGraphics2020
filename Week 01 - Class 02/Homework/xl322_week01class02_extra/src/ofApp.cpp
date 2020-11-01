 #include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	theta = 0;
	frames = 90;
	ofSetVerticalSync(true);
	img.load("indispensable.jpg");
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update(){
	theta += TWO_PI / frames;
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackground(ofColor::black);
	
	// draw the original image
	ofSetColor(ofColor::white);
	img.draw(0, 0);
	
	// draw the four rectangles
	ofRectMode(OF_RECTMODE_CENTER);
	ofNoFill();
	ofSetColor(ofColor::red);
	ofDrawRectangle(mouseX, mouseY, 100+sin(theta)*10, 100+sin(theta)*10);
	
	ofSetColor(ofColor::green);
	ofDrawRectangle(mouseX, mouseY, 50+cos(theta)*10, 50+cos(theta)*10);
	
	ofSetColor(ofColor::blue);
	ofDrawRectangle(mouseX + 25, mouseY + 25, 50-sin(theta) * 5, 50 - sin(theta) * 5);
	
	ofSetColor(ofColor::magenta);
	ofDrawRectangle(mouseX - 25, mouseY - 25, 50 - cos(theta) * 5, 50 - cos(theta) * 5);
	
	// draw the four corresponding subsections
	ofTranslate(427, 0);
	ofSetColor(ofColor::white);
	img.drawSubsection(0, 0, 100 + sin(theta) * 10, 100 + sin(theta) * 10, mouseX, mouseY);
	ofSetColor(ofColor::red);
	ofDrawRectangle(0, 0, 100 + sin(theta) * 10, 100 + sin(theta) * 10);
	
	ofSetColor(ofColor::white);
	img.drawSubsection(0, 100, 100 + cos(theta) * 10, 100 + cos(theta) * 10, mouseX, mouseY, 50, 50);
	ofSetColor(ofColor::green);
	ofDrawRectangle(0, 100, 100 + cos(theta) * 10, 100 + cos(theta) * 10);
	
	ofSetColor(ofColor::white);
	img.drawSubsection(0, 200, 100 - sin(theta) * 5, 100 - sin(theta) * 5, mouseX + 25, mouseY + 25, 50, 50);
	ofSetColor(ofColor::blue);
	ofDrawRectangle(0, 200, 100 - sin(theta) * 5, 100 - sin(theta) * 5);
	
	ofSetColor(ofColor::white);
	img.drawSubsection(0, 300, 100 - cos(theta) * 5, 100 - cos(theta) * 5, mouseX - 25, mouseY - 25, 50, 50);
	ofSetColor(ofColor::magenta);
	ofDrawRectangle(0, 300, 100 - cos(theta) * 5, 100 - cos(theta) * 5);
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