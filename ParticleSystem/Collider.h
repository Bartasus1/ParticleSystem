#pragma once
#include "ofVec3f.h"
#include "Particle.h"
#include "of3dGraphics.h"

class Collider
{
public:
	Collider();

	ofVec3f Position;

	virtual void CalculateCollision(class Particle* particle) = 0;
	virtual void Draw() = 0;
};

