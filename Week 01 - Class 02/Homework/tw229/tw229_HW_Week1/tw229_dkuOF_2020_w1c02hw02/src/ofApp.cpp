#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255, 255, 255);
    for(int i = 0;i<1000;i++){
        Flower tempFlower;
        flowers.push_back(tempFlower);
    }
    image.load("garden.jpg");
   
}

//--------------------------------------------------------------
void ofApp::update(){
    flowerrotating++;
    for(int i = 0;i<mouseclick;i++){
        flowers[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    image.draw(-150,0);
    
    for(int i = 0;i<mouseclick;i++){
       // glPushMatrix();
        //ofTranslate(flowers[i].x, flowers[i].y);
        //ofRotateDeg(flowerrotating);
        flowers[i].draw();
       // glPopMatrix();
    }
    ofSetColor(60);
    ofDrawBitmapString("Please Click to Make More Flowers",ofGetWidth()/2,ofGetHeight()/2);
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
    mouseclick++;
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
