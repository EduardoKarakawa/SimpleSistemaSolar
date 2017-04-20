#include "Planeta.h"

ofVec2f Planeta::GetPosition() const { return m_position; }
float Planeta::GetRadius() const { return m_radius; }
float Planeta::GetMass() const { return m_mass; }

void Planeta::Setup(const ofVec2f &position, float radius, float mass, float velocity, ofVec2f centerPosition) {
	m_position = position;
	m_radius = radius;
	m_mass = mass;
	m_momentum = position;
	m_velocity = velocity;
	m_distance = position.distance(centerPosition);
}


void Planeta::Update(const ofVec2f &solPosition, float solMass, float deltaTime) {
	ofVec2f g = solPosition - m_position;
	float angle = atan2f(g.y, g.x) - 90 * PI /180.0f;
	ofVec2f d = ofVec2f(cos(angle), sin(angle)) * m_distance;
	m_position += (g * ((solMass * m_mass) / pow(m_position.distance(solPosition), 2)) + d).normalized() * m_velocity * deltaTime;

}


void Planeta::Draw(ofColor &color) {
	ofSetColor(color);
	ofDrawCircle(m_position, m_radius);
}


ofVec2f Planeta::DirectionForceAttraction(const ofVec2f &solPosition) {
	return (solPosition - m_position).normalized();
}



