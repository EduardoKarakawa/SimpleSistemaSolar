#include "Sol.h"
ofVec2f Sol::GetPosition() const { return m_position; }
float Sol::GetMass() const { return m_mass; }

void Sol::Setup(ofVec2f position, float radius, float mass) {
	m_position = position;
	m_radius = radius;
	m_mass = mass;
}

void Sol::Draw() {
	ofSetColor(255, 120, 0);
	ofDrawCircle(m_position, m_radius);
}