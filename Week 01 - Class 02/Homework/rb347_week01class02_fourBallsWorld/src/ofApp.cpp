
// Rongqi Bei
#include "ofApp.h"

Boolean set_color = false;
int given_category;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255, 255, 255);
    
    for (int i = 0; i <= 4; i++){
        Ball *ball = new Ball(1, 0, 0);
        ball_vector.push_back(*ball);
    }
    for (int i = 0; i <= 1; i++){
        Ball *ball = new Ball(2, 0, 0);
        ball_vector.push_back(*ball);
    }
    for (int i = 0; i <= 6; i++){
        Ball *ball = new Ball(3, 0, 0);
        ball_vector.push_back(*ball);
    }
    for (int i = 0; i <= 2; i++){
        Ball *ball = new Ball(4, 0, 0);
        ball_vector.push_back(*ball);
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
    
    ofSetColor(50, 50, 50);
    ofFill();
    ofDrawRectangle(0, 400, ofGetWidth(), ofGetHeight()-400);
    ofSetColor(50, 50, 50);
    ofDrawLine(ofGetWidth()/4, 0, ofGetWidth()/4, 400);
    ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, 400);
    ofDrawLine(ofGetWidth()*3/4, 0, ofGetWidth()*3/4, 400);
    ofDrawLine(0, 400, ofGetWidth(), 400);
    
    for (int i = 0; i < ball_vector.size(); i++){
        for (int j = 0; j < ball_vector.size(); j++){
            if (i != j){
                ball_vector[i].collision(ball_vector[j]);
            }
        }
        ball_vector[i].draw();
    }
    
    ofSetColor(255);
    ofDrawBitmapString("YOU ARE CONTROLLING 4 WORLD_OF_BALLS", ofGetWidth()/2-150, 420);
    ofDrawBitmapString("Click the mouse to add new members in the corresponding world. Note: These \"new members\" are a species of the world.\nTap the keyboard before clicking the mouse allows you to add strangers to those worlds.\n[Instruction]\nkey\"y\" -- balls come from the first world; \"b\" -- balls come from the second world; \"r\" -- balls come from the third world; \"g\" -- balls come from the fourth world.", 25, 440);
    if (set_color){
        ofDrawBitmapString("** Add strangers from the         world.", 1250, 440);
        if (given_category == 1){
            ofDrawBitmapString("YELLOW", 1460, 440);
        }
        if (given_category == 2){
            ofDrawBitmapString("BLUE", 1470, 440);
        }
        if (given_category == 3){
            ofDrawBitmapString("RED", 1470, 440);
        }
        if (given_category == 4){
            ofDrawBitmapString("GREEN", 1465, 440);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'y'){
        set_color = true;
        given_category = 1;
    }
    if (key == 'b'){
        set_color = true;
        given_category = 2;
    }
    if (key == 'r'){
        set_color = true;
        given_category = 3;
    }
    if (key == 'g'){
        set_color = true;
        given_category = 4;
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
    
    if (x<ofGetWidth()/4 and x>0 and y<400){
        if (set_color){
            Ball *ball_pressed = new Ball(1, 1, given_category);
            ball_vector.push_back(*ball_pressed);
        }
        else{
            Ball *ball_pressed = new Ball(1, 1, 0);
            ball_vector.push_back(*ball_pressed);
        }
    }
    if (x>ofGetWidth()/4 and x<ofGetWidth()/2 and y<400){
        if (set_color){
            Ball *ball_pressed = new Ball(2, 1, given_category);
            ball_vector.push_back(*ball_pressed);
        }
        else{
            Ball *ball_pressed = new Ball(2, 1, 0);
            ball_vector.push_back(*ball_pressed);
        }
    }
    if (x>ofGetWidth()/2 and x<ofGetWidth()*3/4 and y<400){
        if (set_color){
            Ball *ball_pressed = new Ball(3, 1, given_category);
            ball_vector.push_back(*ball_pressed);
        }
        else{
            Ball *ball_pressed = new Ball(3, 1, 0);
            ball_vector.push_back(*ball_pressed);
        }
    }
    if (x>ofGetWidth()*3/4 and x<ofGetWidth() and y<400){
        if (set_color){
            Ball *ball_pressed = new Ball(4, 1, given_category);
            ball_vector.push_back(*ball_pressed);
        }
        else{
            Ball *ball_pressed = new Ball(4, 1, 0);
            ball_vector.push_back(*ball_pressed);
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    set_color = false;

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
