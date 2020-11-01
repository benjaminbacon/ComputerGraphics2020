#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetWindowTitle("color example");
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    // initialise member variables to the centre of the screen
    mouseXPercent = 0.5f;
    mouseYPercent = 0.5f;
    
    webcam.setup(ofGetWidth(),ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    webcam.draw(ofGetWidth()/2+130,ofGetHeight()/2-20);
   //track the color of one pixel in the image from camera
    ofColor c;
    ofPixels pix = webcam.getPixels();
    c =pix.getColor(ofGetMouseX(),ofGetMouseY());
    ofSetColor( c );
    ofFill();
    ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 100, 100 );
    
    // now draw a white border around the rectangle
    ofNoFill();
    ofSetHexColor(0xFFFFFF);
    ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 100, 100 );
    ofFill();
    
    
    // finally we draw text over the rectangle giving the resulting HSB and RGB values
    // under the mouse
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString("HSB: "+ofToString(int(c.getHue()))+
                       " "+ofToString(int(c.getSaturation()))+
                       " "+ofToString(int(c.getBrightness())),
                       30, ofGetHeight()-10 );
    ofDrawBitmapString("RGB: "+ofToString(int(c.r))+
                       " "+ofToString(int(c.g))+
                       " "+ofToString(int(c.b)),
                       250, ofGetHeight()-10 );
    ofDrawBitmapString("Track the color of One Pixel in Your Cam", 550, ofGetHeight()-10);
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){

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
