#pragma once
#include "Effector.h"

class WindEffector : public Effector
{
public:
	WindEffector();

	ofVec3f Direction = ofVec3f(1, 0, 0);
	float Strength = 0.05;

	virtual void EffectParticles(Particle* particle) override;
};

