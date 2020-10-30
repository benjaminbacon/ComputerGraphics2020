#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255, 255, 255);
    int numflowers = 20;
    for(int i = 0;i<numflowers;i++){
        Flower tempFlower;
        flowers.push_back(tempFlower);
    }
    image.load("garden.jpg");
   
}

//--------------------------------------------------------------
void ofApp::update(){
    flowerrotating++;
    for (int i = 0; i < 20; i++) {
        flowers[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(-150,0);
    for (int i = 0; i < 20; i++) {
       
       // glPushMatrix();
        //ofTranslate(flowers[i].x, flowers[i].y);
        //ofRotateDeg(flowerrotating);
        flowers[i].draw();
       // glPopMatrix();
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
