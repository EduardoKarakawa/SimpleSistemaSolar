#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sol.Setup(ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f), 80.0f, 40.0f);
	terra.Setup(ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f - 200.0f), 30.0f, 10.0f, 360 /5, sol.GetPosition());
	lua.Setup(ofVec2f(terra.GetPosition().x, terra.GetPosition().y - 50), 30.0f, 15.0f, 360, terra.GetPosition());
}

//--------------------------------------------------------------
void ofApp::update(){
	terra.Update(sol.GetPosition(), sol.GetMass(), ofGetLastFrameTime());
	lua.Update(terra.GetPosition(), terra.GetMass(), ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(4, 5, 15);
	sol.Draw();
	terra.Draw(ofColor(0, 120, 255));
	lua.Draw(ofColor(0, 255, 255));
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
