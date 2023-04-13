#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239);
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	for (int x = span * 1.5; x <= ofGetWindowWidth() - span * 1.5; x += span) {

		for (int y = span * 1.5; y <= ofGetWindowHeight() - span * 1.5; y += span) {

			bool flag = ofNoise(x * 0.08, y * 0.08, ofGetFrameNum() * 0.01) < 0.5 ? true : false;

			if (flag) {

				ofDrawLine(x - span * 0.5, y, x + span * 0.5, y);
			}
			else {

				ofDrawLine(x, y - span * 0.5, x, y + span * 0.5);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}