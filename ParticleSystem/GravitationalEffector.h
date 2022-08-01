#pragma once
#include "Effector.h"


class GravitationalEffector : public Effector
{
public:
	GravitationalEffector();

	ofVec3f Position = { 0,100,0 };
	float Strength = 0.1;

	virtual void EffectParticles(Particle* particle) override;
};

