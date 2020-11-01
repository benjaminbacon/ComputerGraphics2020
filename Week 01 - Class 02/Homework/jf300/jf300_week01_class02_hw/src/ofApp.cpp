#include "ofApp.h"
#include "Ball.h"

int nPoints = 512; // points to draw
float complexity = 6; // wind complexity
float pollenMass = .8; // pollen mass
float timeSpeed = .02; // wind variation speed
float phase = TWO_PI; // separate u-noise from v-noise
float windSpeed = 40; // wind vector magnitude for debug
int step = 10; // spatial sampling rate for debug
bool debugMode = false;
bool lowFrameRateProtect = false;
int timeExsit = 65536; // the num of frames each point remains on screen
int resetFrame = 0; // last time the mesh reset


glm::vec2 ofApp::getField(const glm::vec2& position) {
	float normx = ofNormalize(position.x, 0, ofGetWidth());
	float normy = ofNormalize(position.y, 0, ofGetHeight());
	float u = ofNoise(t + phase, normx * complexity + phase, normy * complexity + phase);
	float v = ofNoise(t - phase, normx * complexity - phase, normy * complexity + phase);
	return glm::vec2(u, v);
}

//--------------------------------------------------------------
void ofApp::setup(){
	ball.setup();
	ofBackground(255);

	//from noise 2d
	//ofSetVerticalSync(true); // don't go too fast
	ofEnableAlphaBlending();

	// randomly allocate the points across the screen
	points.resize(nPoints);
	for (int i = 0; i < nPoints; i++) {
		points[i] = glm::vec2(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	}

	// we'll be drawing the points into an ofMesh that is drawn as bunch of points
	cloud.clear();
	cloud.setMode(OF_PRIMITIVE_POINTS);

}

//--------------------------------------------------------------
void ofApp::update(){

	if (ofGetKeyPressed(OF_KEY_BACKSPACE)) {
		cloud.clear();
		resetFrame = ofGetFrameNum();
		timeExsit = 65536;
		lowFrameRateProtect = false;
	}

	//from noise 2d
	width = ofGetWidth(), height = ofGetHeight();
	t = ofGetFrameNum() * timeSpeed;

	for (int i = 0; i < nPoints; i++) {
		float x = points[i].x, y = points[i].y;
		glm::vec2 field = getField(points[i]); // get the field at this position
		// use the strength of the field to determine a speed to move
		// the speed is changing over time and velocity-space as well
		float speed = (1 + ofNoise(t, field.x, field.y)) / pollenMass;
		// add the velocity of the particle to its position 
		x += ofLerp(-speed, speed, field.x);
		y += ofLerp(-speed, speed, field.y);
		// if we've moved outside of the screen, reinitialize randomly
		if (x < 0 || x > width || y < 0 || y > height) {
			x = ofRandom(0, width);
			y = ofRandom(0, height);
		}
		// save the changes we made to the position
		points[i].x = x;
		points[i].y = y;
		// add the current point to our collection of drawn points
		cloud.addVertex(ofPoint(x, y));
		cloud.addColor({ 0,0.1 });
	}

	ball.update();
	float ballX = ball.x;
	float ballY = ball.y;
	bool ballState = ball.state;
	float dim = ball.dim;
	float ballSize = ball.BALLSIZE;

	for (int j = max(0,(int)cloud.getNumVertices() - timeExsit * nPoints); j < (int)cloud.getNumVertices(); j++) {
		ofDefaultVertexType a = cloud.getVertex(j);
		if (a.x < ballX + (ballSize-dim) && a.x > ballX - (ballSize - dim) && a.y < ballY + (ballSize - dim) && a.y > ballY - (ballSize - dim)) cloud.setColor(j,255);
		else if (sqrt((a.x - ballX)*(a.x - ballX) + (a.y - ballY)*(a.y - ballY)) < dim) cloud.setColor(j, 255);

	}

	// Automatic low frame rate detection
	if (!lowFrameRateProtect && ofGetFrameNum() - resetFrame > 120 && ofGetFrameRate() < 50) {
		timeExsit = ofGetFrameNum() - resetFrame;
		lowFrameRateProtect = true;
		cout << "low fram rate protection is triggered, the exsitance number of frames for each point is: ";
		cout << timeExsit << endl;
	}

	if (lowFrameRateProtect && (int)cloud.getNumVertices() >= timeExsit * nPoints) {
		for (int k = cloud.getNumVertices() - timeExsit * nPoints; k < (int)cloud.getNumVertices() - (timeExsit - 1) * nPoints; k++) cloud.setColor(k, 255);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	cloud.draw();
	ball.draw();
	ofDrawBitmapStringHighlight("when it gets stuck \npress BACKSPACE to reset", 10, 10, ofColor::white, ofColor::black);
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
