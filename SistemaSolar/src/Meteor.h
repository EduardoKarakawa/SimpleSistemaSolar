#pragma once
#include <vector>
#include "ofVec2f.h"
#include "ofGraphics.h"
#include "ofAppRunner.h"
#include "Planet.h"

#define MIN_MASS 5.0f
#define MAX_MASS 50.0f

class Meteor
{

private:
	ofVec2f m_momentum; 
	ofVec2f m_position;
	float m_radius;
	float m_mass;
	bool m_collided;
public:
	Meteor();
	void Update(const std::vector<Planet> &planets, const float &deltatime);
	void Draw();
	bool OnScreen();
	const ofVec2f & GetPosition() const;
	const bool & Collided() const;

};

