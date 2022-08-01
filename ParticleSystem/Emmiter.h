#pragma once
#include "Particle.h"
#include <vector>

class Emmiter
{
public:
	Emmiter();
	Emmiter(ofVec3f StartPosition);

	void SetPosition(ofVec3f NewPosition);

	virtual void Emmit() = 0;

protected:
	Particle* GetParticle();

	ofVec3f Position;
	
};

