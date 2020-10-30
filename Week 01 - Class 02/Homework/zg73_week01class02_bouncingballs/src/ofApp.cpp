#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,255,255);
    int number_of_balls = 50;
    for(int i=0;i<number_of_balls;i++){
        Ball *ball = new Ball();
        group_of_balls.push_back(*ball);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<group_of_balls.size();i++){
        group_of_balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<group_of_balls.size();i++){
        for(int ii=0;ii<group_of_balls.size();ii++){
            if(i!=ii){
                group_of_balls[i].same(group_of_balls[ii]);
                group_of_balls[i].crash(group_of_balls[ii]);
            }
        }
        group_of_balls[i].draw();
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
