#pragma once
#include "ofVec2f.h"
#include "ofGraphics.h"

class Planeta {
private:
	ofVec2f m_position, m_momentum, m_direction;
	float m_radius;
	float m_mass;
	float m_velocity;
	float m_distance;

public:
	void Setup(const ofVec2f &position, float radius, float mass, float velocity, ofVec2f centerPosition);
	void Update(const ofVec2f &solPosition, float solMass, float deltaTime);
	void Draw(ofColor &color);
	ofVec2f GetPosition() const;
	float GetRadius() const;
	float GetMass() const;
	ofVec2f DirectionForceAttraction(const ofVec2f &solPosition);
};