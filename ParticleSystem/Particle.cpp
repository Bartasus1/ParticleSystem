#include "Particle.h"
#include "math/ofMath.h"
#include "ofGraphics.h"


Particle::Particle()
{
	Color = ofColor(ofRandom(20, 254), ofRandom(20, 254), ofRandom(20, 254));
}

void Particle::Update()
{
	Lifespan -= ofGetLastFrameTime();
	Color.a = ofLerp(0, 1, (float)(Lifespan / MaxLifespan));

	Velocity += Acceleration;
	Velocity.limit(10);
	Position += Velocity;

	Acceleration = ofVec3f(0);
}

void Particle::SetLifespan(float NewLifespan)
{
	Lifespan = NewLifespan;
	MaxLifespan = Lifespan;
}

void Particle::AddForce(ofVec3f Force)
{
	Acceleration += Force;
}

