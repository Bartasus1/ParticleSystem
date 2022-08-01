#pragma once
#include "3d/of3dPrimitives.h"
#include "ofVec3f.h"
#include "ofColor.h"


class Particle
{
public:
	Particle();

	ofVec3f Position;
	ofVec3f Velocity;
	ofVec3f Acceleration;

	// lifespan in seconds
	float Lifespan = 5;
	float MaxLifespan = Lifespan;

	float Radius = 5;
	bool bHasCollisions = true;

	ofFloatColor Color;

	void Update();
	void SetLifespan(float NewLifespan);

	void AddForce(ofVec3f Force);
	
};

