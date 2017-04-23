#include "Meteor.h"

Meteor::Meteor() { Setup(); }
const ofVec2f & Meteor::GetPosition() const { return m_position; }
const bool &Meteor::Collided() const { return m_collided; }


void Meteor::Setup() {
	m_position = ofVec2f((rand() % 2) * ofGetWidth(), rand() % ofGetHeight());
	float tmp = (1000 + rand() % 5000) / 100.0f;
	m_radius = 5 + rand() % 30;
	m_mass = m_radius * 1.5f;
	m_momentum = ofVec2f(ofGetWidth() / 2.0f - m_position.x , ((rand() % 2) * 2 - 1) * rand() % (ofGetHeight() / 4)).normalized() * tmp;
	m_collided = false;
}

void Meteor::Update(const std::vector<Planet> &planets, const float &deltatime) {
	ofVec2f forces = ofVec2f(0, 0);
	
	// Percorre a lista de planetas e adiona as forcas de atracao se o meteoro estiver na area de atracao
	for (int i = 0; i < 3; i++) {
		float distance = m_position.distance(planets[i].GetPosition());
		if (distance <= planets[i].GetRadiusAtraction()) {
			m_collided = m_collided || distance <= planets[i].GetSize();
			// Calcula a forca de atracao
			float atraction = (m_mass * planets[i].GetMass() * 250.0f) / pow(m_position.distance(planets[i].GetPosition()), 2);
			
			// Gera a direcao para onde deve ser a plicado a gravidade
			ofVec2f direction = planets[i].GetPosition() - m_position;

			// Soma das forcas
			forces += direction.normalized() * atraction;
		}
	}
	
	ofVec2f acceleration = forces / m_mass;
	m_position += (m_momentum + acceleration / 2.0f) * deltatime;
	m_momentum += acceleration * deltatime;
}



void Meteor::Draw() {
	ofDrawCircle(m_position, m_radius);
}


bool Meteor::OnScreen() {
	return	((m_position.x > -10 && m_position.x < ofGetWidth() + 10) &&
			(m_position.y > -10 && m_position.y < ofGetHeight() + 10));
}