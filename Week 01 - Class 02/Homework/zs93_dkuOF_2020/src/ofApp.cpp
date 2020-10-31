#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(ofColor::peachPuff);
    Pipe p = Pipe();
    pipe.push_back(p);
    font.load("Iron.ttf", 90);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(finish){
        return;
    }
    ball.update();
    for (int i=0; i<pipe.size(); i++){
        pipe[i].update();
    }
    if (pipe.back().X < 3*ofGetWidth()/4){
        Pipe p = Pipe();
        pipe.push_back(p);
    }
    if (pipe.size() && pipe[0].X<=0){
        pipe.erase(pipe.begin());
    }
    for (int i=0; i<pipe.size(); i++){
        if (ball.y >= ofGetHeight()-ball.radius){
            finish = true;
        }
        if (pipe[i].X == ball.x+ball.radius) cnt++;
        if (pipe[i].X+pipe[i].width>=ball.x-ball.radius &&
            pipe[i].X<=ball.x+ball.radius){
            if (ball.y-ball.radius<=pipe[i].lower || ball.y+ball.radius>=pipe[i].upper){
                finish = true;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball.draw();
    for (int i=0; i<pipe.size(); i++){
        pipe[i].draw();
    }
    string str = "Your Score: "+to_string(cnt);
    ofDrawBitmapString(str, 50, 50);
    if (finish){
        gameOver();
    }
}

void ofApp::gameOver(){
    font.drawString("Game Over!", ofGetWidth()/2-270, ofGetHeight()/2+30);
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
    ball.click_update();
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
