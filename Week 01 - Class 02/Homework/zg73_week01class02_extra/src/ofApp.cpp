

#include "ofApp.h"
int a1,a2;
int b1,b2;
int c1,c2;
ofColor a_color= ofColor(255, 255, 255);
ofColor b_color = ofColor(255, 255, 255);
ofColor c_color = ofColor(255, 255, 255);

//--------------------------------------------------------------
void ofApp::setup(){
    

    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetFrameRate(60);
    mouseXPercent = 0.5f;
    mouseYPercent = 0.5f;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ball1.update();
    ball2.update();
    ball3.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor( 255 );
    ofFill();
    ofDrawRectangle( (ofGetWidth()-ofGetHeight())/2+ofGetHeight() , ofGetHeight()/2, ofGetWidth()-ofGetHeight(), ofGetHeight() );  // Rxoxanne: the size has main changed
    
    float hue = fmodf(ofGetElapsedTimef()*10,255);
    
    int step = 5;
    // step through horizontally
    for ( int i=0; i<ofGetHeight(); i+=step )
    {
        // step through vertically
        for ( int j=0; j<ofGetHeight(); j+=step )
        {
            // set HSB using our hue value that changes over time, saturation from the X position (i),
            // and brightness from the Y position (j). we also invert the Y value since it looks
            // nicer if the dark/black colors are along the bottom.
            ofColor c;
            // the range of each of the arguments here is 0..255 so we map i and j to that range.
            c.setHsb( hue, ofMap(i, 0,ofGetHeight(), 0,255), ofMap(j, ofGetHeight(),0, 0,255 ) );
            
            // assign the color and draw a rectangle
            ofSetColor( c );
            ofDrawRectangle( i, j, step-1, step-1 );
        }
    }
    
    // now we will draw a larger rectangle taking the color under the mouse
    
    // calculate the color under the mouse, using the same calculations as when drawing the grid,
    // using mouseX and mouseY in place of i and j; draw a rectangle with this color. here we use
    // ofColor::fromHsb which allows us to set the HSB color in a single line of code.
    ofColor color = ofColor::fromHsb(hue,
                                     ofMap( mouseX, 0,ofGetHeight(), 0,255 ),
                                     ofMap( mouseY, ofGetHeight(),0, 0,255 ) );
    //ofFill();
    
    if (mouseX <= ofGetHeight()){  // Roxanne: a if logic is added because the size of the canvas has been changed.
        ofSetColor( color );
        ofFill();
        ofDrawRectangle( mouseX, mouseY, 100, 100 );
        // now draw a white border around the rectangle
        ofNoFill();
        ofSetHexColor(0xFFFFFF);
        ofSetLineWidth(1.5);
        ofDrawRectangle( mouseX, mouseY, 100, 100 );
    }
    
    // finally we draw text over the rectangle giving the resulting HSB and RGB values
    // under the mouse
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString("HSB: "+ofToString(int(hue))+
                       " "+ofToString(int(color.getSaturation()))+
                       " "+ofToString(int(color.getBrightness())),
                       10, ofGetHeight()-13 );
    ofDrawBitmapString("RGB: "+ofToString(int(color.r))+
                       " "+ofToString(int(color.g))+
                       " "+ofToString(int(color.b)),
                       200, ofGetHeight()-13 );
 
    ofDrawBitmapString("In the left part, tape 1,2,3 to change the color of frame", 10, ofGetHeight()-60);
    ofDrawBitmapString("In the right part, tape 1,2 3,to change the color of circle", 10, ofGetHeight()-30);
    
    // ----------------------- Roxanne's main modification in draw() starts here
    
    // For each region that colors can be filled in,
    // we need two variables to decide whether to pass new color value to the filling color or not.
    // When the corresponding key is pressed, a new color is needed,
    // which is represented by adding 1 to the first variable.
    // Therefore, if there are differences between the two variables, a new color value needed to be passed.
    
    // Judge whether new color value should be passed:
    

    
    // After passing the color value, we add 1 to the second variable to make the two variables again the same
    // Therefore, if the two variables are equal, we know a new color value has already been passed
    // and we need to refill the corresponding region with the new color.
    
    // Filling the corresponding region with the new color:
    ball1.draw();
    ball2.draw();
    ball3.draw();
    if (a1 != a2){
        a_color = color;
        a2 += 1;
    }
    if (b1 != b2){
       b_color = color;
        b2 += 1;
    }
    if (c1 != c2){
        c_color = color;
        c2 += 1;
    }
    if (a1 == a2){
        ball1.color = a_color;
    }
    if (b1 == b2){
        ball2.color = b_color;
    }
    if (c1 == c2){
        ball3.color = c_color;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == '1'){
        a1 += 1;
    }
    if (key == '2'){
        b1 += 1;
    }
    if (key == '3'){
        c1 += 1;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    // update mouse x and y percent when the mouse moves
    mouseXPercent = float(x) / ofGetHeight();
    mouseYPercent = float(y) / ofGetHeight();

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
