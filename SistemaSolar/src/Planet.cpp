#include "Planet.h"
const ofVec2f & Planet::GetPosition() const { return m_position; }
const float & Planet::GetMass() const { return m_mass; }
const float & Planet::GetRadiusAtraction() const { return m_mass; }
const float & Planet::GetSize() const { return m_size; }


Planet::Planet() {
	m_position.set(0, 0);
	m_mass = 0;
	m_radiusAtraction = 0;
	m_velocity = 0;
	m_size = 0;
	m_angle = 0;
}


Planet::Planet(const ofVec2f &center, float distance, float radiusAtraction, float velocity, float mass, float size) {
	m_position.set(center + ofVec2f(1,0) * distance);
	m_distance = distance;
	m_mass = mass;
	m_radiusAtraction = radiusAtraction;
	m_velocity = velocity;
	m_size = size;
	m_angle = 0;
}


void Planet::Setup(const ofVec2f &center, float distance, float radiusAtraction, float velocity, float mass, float size) {
	m_position.set(center + ofVec2f(1, 0) * distance);
	m_distance = distance;
	m_mass = mass;
	m_radiusAtraction = radiusAtraction;
	m_velocity = velocity;
	m_size = size;
	m_angle = 0;
}


void Planet::Update(const ofVec2f &center, float &deltaTime) {
	m_angle = m_angle > 360 ? 0 : m_angle + m_velocity * deltaTime;

	m_position = center + ofVec2f(cosf(m_angle * PI / 180.f), sinf(m_angle * PI / 180.f)) * m_distance;
}


void Planet::Draw() {
	ofSetColor(0, 0, 175, 20);
	ofDrawCircle(m_position, m_radiusAtraction);
	ofSetColor(255, 255, 255);
	ofDrawCircle(m_position, m_size);

}

Planet::~Planet()
{
}
