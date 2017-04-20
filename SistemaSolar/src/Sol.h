#pragma once
#include "ofVec2f.h"
#include "ofGraphics.h"

class Sol {
	private:
		ofVec2f m_position;
		float m_radius;
		float m_mass;

	public:
		void Setup(ofVec2f position, float radius, float mass);
		void Draw();
		ofVec2f GetPosition() const;
		float GetMass() const;
};