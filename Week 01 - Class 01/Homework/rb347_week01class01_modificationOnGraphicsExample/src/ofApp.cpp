#include "ofApp.h"

int left_sleeve1, left_sleeve2;
int right_sleeve1, right_sleeve2;
int body1, body2;
int left_trouser1, left_trouser2;
int right_trouser1, right_trouser2;


ofColor left_sleeve_color = ofColor(255, 255, 255);
ofColor right_sleeve_color = ofColor(255, 255, 255);
ofColor body_color = ofColor(255, 255, 255);
ofColor left_trouser_color = ofColor(255, 255, 255);
ofColor right_trouser_color = ofColor(255, 255, 255);


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

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    // here we demonstrate setting colors using HSB (Hue/Saturation/Brightness) rather than the
    // more well-known RGB (Red/Green/Blue).
    
    // HSB allows colors to be specified in a way that is perhaps more natural to the understanding
    // of color that we have through language, using numerical values to describe 'hue',
    // 'saturation' and 'brightness'.
    
    // 'hue' refers to the 'color' in the rainbow sense, moving from red through yellow through
    //   green through blue through purple through red, looping around again.
    // 'saturation' refers to the intensity of the color. high saturation means intense color,
    //   low saturation means washed out or black and white.
    // 'brightness' refers to how light or dark the color is. high brightness means a bright color,
    //   low brightness is dark. if the brightness is 0 the resulting color will be black, regardless
    //   of the values for hue or saturation.
        
    // in ofColor all the values are specified as 0..255 .
    
    // for example, to specify an orange color that is strong and bright, you start by specifying the
    // hue for the orange you want (a number from 15-30, 15 is more red and 30 is more yellow), then
    // the saturation (something between 180 and 255 for high saturation) and the brightness (180 to
    // 255 for bright).
    
    // for grays (and black and white) you can use any value for hue, set the saturation to 0 and
    // control the level of gray with the brightness value: 255 is white, 0 is black, 128 is 50% gray.

    
    
    // we want to draw a grid of 5 pixel x 5 pixel rectangles with a fixed hue, varying in
    // saturation and brightness over X and Y
    
    // we use one hue (value from 0..255) for the whole grid. it changes over time. we use f to
    // keep the hue value between 0 and 255, it works just like integer modulo (the % operator) but
    // for floats.
    
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
    
    // ----------------------- Roxanne's main modification in draw() starts here
    
    // For each region that colors can be filled in,
    // we need two variables to decide whether to pass new color value to the filling color or not.
    // When the corresponding key is pressed, a new color is needed,
    // which is represented by adding 1 to the first variable.
    // Therefore, if there are differences between the two variables, a new color value needed to be passed.
    
    // Judge whether new color value should be passed:
    
    if (left_sleeve1 != left_sleeve2){
        left_sleeve_color = color;
        left_sleeve2 += 1;
    }
    if (right_sleeve1 != right_sleeve2){
        right_sleeve_color = color;
        right_sleeve2 += 1;
    }
    if (body1 != body2){
        body_color = color;
        body2 += 1;
    }
    if (left_trouser1 != left_trouser2){
        left_trouser_color = color;
        left_trouser2 += 1;
    }
    if (right_trouser1 != right_trouser2){
        right_trouser_color = color;
        right_trouser2 += 1;
    }
    
    // After passing the color value, we add 1 to the second variable to make the two variables again the same
    // Therefore, if the two variables are equal, we know a new color value has already been passed
    // and we need to refill the corresponding region with the new color.
    
    // Filling the corresponding region with the new color:
    
    if (left_sleeve1 == left_sleeve2){
        ofSetColor( left_sleeve_color );
        ofFill();
        ofBeginShape();
        ofVertex(900, 100);
        ofVertex(800, 250);
        ofVertex(850, 300);
        ofVertex(910.9, 208.7);
        ofVertex(900, 100);
        ofEndShape();
    }
    if (right_sleeve1 == right_sleeve2){
        ofSetColor( right_sleeve_color );
        ofFill();
        ofBeginShape();
        ofVertex(1150, 100);
        ofVertex(1250, 250);
        ofVertex(1200, 300);
        ofVertex(1139.1, 208.7);
        ofVertex(1150, 100);
        ofEndShape();
    }
    if (body1 == body2){
        ofSetColor( body_color );
        ofFill();
        ofBeginShape();
        ofVertex(900, 100);
        ofVertex(975, 100);
        ofVertex(1025, 225);
        ofVertex(1075, 100);
        ofVertex(1150, 100);
        ofVertex(1125, 350);
        ofVertex(925, 350);
        ofVertex(900, 100);
        ofEndShape();
    }
    if (left_trouser1 == left_trouser2){
        ofSetColor( left_trouser_color );
        ofFill();
        ofBeginShape();
        ofVertex(925, 350);
        ofVertex(850, 650);
        ofVertex(1000, 650);
        ofVertex(1025, 350);
        ofVertex(925, 350);
        ofEndShape();
    }
    if (right_trouser1 == right_trouser2){
        ofSetColor( right_trouser_color );
        ofFill();
        ofBeginShape();
        ofVertex(1125, 350);
        ofVertex(1200, 650);
        ofVertex(1050, 650);
        ofVertex(1025, 350);
        ofVertex(1125, 350);
        ofEndShape();
    }
    
    // Draw the outline of the different parts of the costume:
    
    ofNoFill();
    ofSetHexColor(0x000000);
    ofSetLineWidth(2.5);
    
    // left sleeves
    ofBeginShape();
    ofVertex(900, 100);
    ofVertex(800, 250);
    ofVertex(850, 300);
    ofVertex(910.9, 208.7);
    ofVertex(900, 100);
    ofEndShape();
    
    // right sleeves
    ofBeginShape();
    ofVertex(1150, 100);
    ofVertex(1250, 250);
    ofVertex(1200, 300);
    ofVertex(1139.1, 208.7);
    ofVertex(1150, 100);
    ofEndShape();
    
    // body
    ofBeginShape();
    ofVertex(900, 100);
    ofVertex(975, 100);
    ofVertex(1025, 225);
    ofVertex(1075, 100);
    ofVertex(1150, 100);
    ofVertex(1125, 350);
    ofVertex(925, 350);
    ofVertex(900, 100);
    ofEndShape();
    
    // left trouser
    ofBeginShape();
    ofVertex(925, 350);
    ofVertex(850, 650);
    ofVertex(1000, 650);
    ofVertex(1025, 350);
    ofVertex(925, 350);
    ofEndShape();
    
    // right trouser
    ofBeginShape();
    ofVertex(1125, 350);
    ofVertex(1200, 650);
    ofVertex(1050, 650);
    ofVertex(1025, 350);
    ofVertex(1125, 350);
    ofEndShape();
    
    // instruction text:
    
    ofSetColor(0);
    ofDrawBitmapString("Press the keyboard to design your costume!\nPlease move your mouse around to feel different color.", 780, 35);
    ofDrawBitmapString("[Keyboard Using Instruction] key \"s\" - the main upper body;\nkey \"a\" - left sleeve;  key \"d\" - right sleeve;\nkey \"z\" - left trouser; key \"x\" - right trouser", 780, 690);
    
    ofSetColor( 255, 250, 240 );
    ofFill();
    ofDrawRectangle(1300+(ofGetWidth()-1300)/2, ofGetHeight()/2, ofGetWidth()-1300, ofGetHeight());
        
    ofSetColor(0);
    ofDrawBitmapString("[Your Design Details]", 1330, 160);
    ofDrawBitmapString("\nThe main upper body:\nR: " + ofToString(int(body_color.r))+"\nG: " + ofToString(int(body_color.g))+"\nG: " + ofToString(int(body_color.b)), 1330, 200);
    ofDrawBitmapString("\nThe left sleeve:\nR: " + ofToString(int(left_sleeve_color.r))+"\nG: " + ofToString(int(left_sleeve_color.g))+"\nB: " + ofToString(int(left_sleeve_color.b)), 1330, 280);
    ofDrawBitmapString("\nThe right sleeve:\nR: " + ofToString(int(right_sleeve_color.r))+"\nG: " + ofToString(int(right_sleeve_color.g))+"\nB: " + ofToString(int(right_sleeve_color.b)), 1330, 360);
    ofDrawBitmapString("\nThe left trouser:\nR: " + ofToString(int(left_trouser_color.r))+"\nG: " + ofToString(int(left_trouser_color.g))+"\nB: " + ofToString(int(left_trouser_color.b)), 1330, 440);
    ofDrawBitmapString("\nThe right trouser:\nR: " + ofToString(int(right_trouser_color.r))+"\nG: " + ofToString(int(right_trouser_color.g))+"\nB: " + ofToString(int(right_trouser_color.b)), 1330, 520);
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 's'){
        body1 += 1;
    }
    if (key == 'a'){
        left_sleeve1 += 1;
    }
    if (key == 'z'){
        left_trouser1 += 1;
    }
    if (key == 'x'){
        right_trouser1 += 1;
    }
    if (key == 'd'){
        right_sleeve1 += 1;
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
