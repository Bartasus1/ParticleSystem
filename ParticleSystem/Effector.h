#pragma once

#include "ofVec3f.h"
#include "Particle.h"

class Effector
{
public:
	Effector();

	ofVec3f Force;

	virtual void EffectParticles(Particle* particle) = 0;
};

