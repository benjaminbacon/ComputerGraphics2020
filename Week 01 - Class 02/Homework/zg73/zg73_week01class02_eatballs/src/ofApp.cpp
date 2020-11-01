#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    


}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<group_of_balls.size();i++){
        group_of_balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("Tape c to create your ball, use w,a,s,d to control the move and use x to stop", 10, ofGetHeight()-50);
    ofDrawBitmapString("Click to create balls", 10, ofGetHeight()-70);
    ofDrawBitmapString("Tape k to let your ball become bigger, Tape j to let your ball become smaller", 10, ofGetHeight()-30);

    ofDrawBitmapString("You can control your ball to eat the ball", 10, ofGetHeight()-10);
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
    if(key == 'c'){
        Ball *player = new Ball(0,0,1);
        group_of_balls.push_back(*player);
    }
    if(key == 'w'){
        for(int i=0;i<group_of_balls.size();i++){
            if(group_of_balls[i].play==1){
                group_of_balls[i].Vy -= 5;
            }
        }
    }
    if(key == 's'){
        for(int i=0;i<group_of_balls.size();i++){
            if(group_of_balls[i].play==1){
                group_of_balls[i].Vy += 5;
            }
        }
    }
    if(key == 'a'){
        for(int i=0;i<group_of_balls.size();i++){
            if(group_of_balls[i].play==1){
                group_of_balls[i].Vx -= 5;
            }
        }
    }
    if(key == 'd'){
        for(int i=0;i<group_of_balls.size();i++){
            if(group_of_balls[i].play==1){
                group_of_balls[i].Vx += 5;
            }
        }
    }
    if(key == 'x'){
        for(int i=0;i<group_of_balls.size();i++){
            if(group_of_balls[i].play==1){
                group_of_balls[i].Vx = 0;
                group_of_balls[i].Vy = 0;
            }
        }
    }
    if(key == 'k'){
        for(int i=0;i<group_of_balls.size();i++){
            if(group_of_balls[i].play == 1){
                group_of_balls[i].r += group_of_balls[i].r*0.3;
            }
        }
    }
    if(key == 'j'){
        for(int i=0;i<group_of_balls.size();i++){
            if(group_of_balls[i].play == 1){
                group_of_balls[i].r -= group_of_balls[i].r*0.3;
            }
        }
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


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for(int i=0;i<10;i++){
        Ball *ball = new Ball(x,y,0);
        group_of_balls.push_back(*ball);
    }
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
