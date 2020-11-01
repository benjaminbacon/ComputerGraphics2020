#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(118); // let's use a predefined color as our background
    Ball cur1;
    SquareBall cur2;
    b.push_back(cur1);
    sb.push_back(cur2);

}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i=0;i<b.size();i++) b[i].update();
    for (int i=0;i<sb.size();i++) sb[i].update();

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i=0;i<b.size();i++) b[i].draw();
    for (int i=0;i<sb.size();i++) sb[i].draw();

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

    setup();
     update();
     draw();
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
