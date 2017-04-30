#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"

class Planet
{
	private:
		ofVec2f m_position;
		ofColor m_color;
		float m_distance;
		float m_radiusAtraction;
		float m_velocity;
		float m_mass;
		float m_size;
		float m_angle;

	public:
		Planet();
		Planet(const ofVec2f &center, float distance, float radiusAtraction, float velocity, float mass, float size, ofColor color);
		void Update(const ofVec2f &center, float &deltaTime);
		void Draw();
		const ofVec2f & GetPosition() const;
		const float & GetMass() const;
		const float & GetRadiusAtraction() const;
		const float & GetSize() const;
		
		~Planet();
};

