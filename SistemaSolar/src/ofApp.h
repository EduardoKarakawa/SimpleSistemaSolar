#pragma once

#include <vector>
#include <time.h>
#include "ofMain.h"
#include "Planet.h"
#include "Meteor.h"

#define TIME_SPAWN_METEOR 1.5f

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		enum Planets {
			Sun,
			Earth,
			Moon
		};

		float contTime;
		std::vector<Planet> SolarSystem; 
		std::vector<Meteor> Meteors;
};
