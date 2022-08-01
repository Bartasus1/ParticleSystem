#include "PointEmmiter.h"

PointEmmiter::PointEmmiter()
{
}

void PointEmmiter::Emmit()
{
	int ParticlesCount = 3;
	float MaxVelocity = 5;

	for (int i = 0; i < ParticlesCount; i++)
	{
		Particle* particle = GetParticle();

		particle->Position = Position;
		particle->Velocity = ofVec3f(ofRandom(-MaxVelocity, MaxVelocity), ofRandom(-MaxVelocity, MaxVelocity), ofRandom(-MaxVelocity, MaxVelocity));
		particle->SetLifespan(1.5);
	}
}
