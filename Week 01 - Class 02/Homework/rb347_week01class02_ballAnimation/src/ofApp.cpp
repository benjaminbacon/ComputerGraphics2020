#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(255, 255, 255);
    int num_of_balls = 80;
    for (int i = 0; i < num_of_balls; i++){
        if (i < num_of_balls*2/3){
            Ball *ball = new Ball(0);
            ball_vector.push_back(*ball);
        }
        else{
            Ball *ball = new Ball(1);
            ball_vector.push_back(*ball);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < ball_vector.size(); i++){
        ball_vector[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 245, 238);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth()/2, ofGetHeight());
    
    ofSetColor(235, 240, 247);
    ofFill();
    ofDrawRectangle(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    
    for (int i = 0; i < ball_vector.size(); i++){
        for (int j = 0; j < ball_vector.size(); j++){
            if (i != j){
                ball_vector[i].collision(ball_vector[j]);
            }
        }
        ball_vector[i].draw();
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
