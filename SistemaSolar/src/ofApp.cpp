#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	srand(time(NULL));

	ofVec2f sunPos = ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	//															,distance, radiusAtraction, velocity, mass,size
	SolarSystem.push_back(Planet(sunPos,							0,   350,  0,			   1989, 80, ofColor(255, 157, 0)));
	SolarSystem.push_back(Planet(SolarSystem[Sun].GetPosition(),	350,  85,  360 / 15.0f,	   200,  20, ofColor(0, 135, 255)));
	SolarSystem.push_back(Planet(SolarSystem[Earth].GetPosition(),	85,   30,  360.0f / 3.5f,  50,    8,  ofColor(149, 152, 153)));
	contTime = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
	float deltaTime = ofGetLastFrameTime();
	SolarSystem[Sun].	Update(SolarSystem[Sun].GetPosition(),	 deltaTime);
	SolarSystem[Earth].	Update(SolarSystem[Sun].GetPosition(),	 deltaTime);
	SolarSystem[Moon].	Update(SolarSystem[Earth].GetPosition(), deltaTime);
	
	contTime += deltaTime;
	if (contTime >= TIME_SPAWN_METEOR) {
		contTime -= TIME_SPAWN_METEOR;
		Meteors.push_back(Meteor());
	}


	// Percorre os meteros atualizando os que estao na tela e exclui os que nao estao
	for (int i = 0; i < Meteors.size(); i++) {
		if (Meteors[i].OnScreen() && !Meteors[i].Collided()) {
			Meteors[i].Update(SolarSystem, deltaTime);
		}
		else {
			Meteors.erase(Meteors.begin() + i);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(10, 10, 15);
	ofSetColor(255, 255, 255);
	for (Planet i : SolarSystem) {
		i.Draw();
	}

	ofSetColor(115, 50, 50);
	for (Meteor i : Meteors) {
		i.Draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	Meteors.push_back(Meteor());
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
