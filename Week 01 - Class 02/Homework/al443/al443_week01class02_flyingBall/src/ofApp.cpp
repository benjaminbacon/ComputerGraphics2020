#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(255, 255, 255);
	ofBackground(ofColor::peachPuff);


}

//--------------------------------------------------------------
void ofApp::update() {
	for (vector<Ball>::iterator it = balls.begin(); it != balls.end();++it) {
		(*it).update();
		if (player != NULL) {
			if ((*player).Collide(*it)) it->radius=0;

		}

	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 0, 0);

	ofDrawBitmapString("Left click to create one ball, right click to create many balls", 10, ofGetHeight() - 50);
	ofDrawBitmapString("Press n to create your player, use w,a,s,d to control it", 10, ofGetHeight() - 30);
	ofDrawBitmapString("Control your player to destroy all the balls!", 10, ofGetHeight() - 10);
	for (int i = 0; i < balls.size(); i++) {
		balls[i].draw();
	}
	if (player!=NULL) (*player).draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'n') {
		player = new Player(0, 0,20);
	}
	if (key == 'a') player->x -= player->v;
	if (key == 'd') player->x += player->v;
	if (key == 'w') player->y -= player->v;
	if (key == 's') player->y += player->v;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	if (button == 0) {
		Ball  first = Ball(x,y);
		balls.push_back(first);
	}
	if (button == 2) {
		Ball t = Ball(x, y);
		for (int i = 0; i < 9; i++) {
			Ball ball = Ball(x, y);
			ball.color = t.color;
			ball.radius = t.radius;
			balls.push_back(ball);
		}
	}

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
