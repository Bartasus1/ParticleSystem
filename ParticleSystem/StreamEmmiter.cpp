#include "StreamEmmiter.h"

StreamEmmiter::StreamEmmiter()
{
}

void StreamEmmiter::SetDirection(ofVec3f NewDirection)
{
	Direction = NewDirection.getNormalized();
}

void StreamEmmiter::Emmit()
{
	int ParticleCount = 7;

	for (int i = 0; i < ParticleCount; i++)
	{
		Particle* particle = GetParticle();

		particle->Position = Position + ofRandom(-PositionVariation, PositionVariation);
		particle->Velocity = Direction * (Velociy + ofRandom(-VelocityVariation, VelocityVariation));
		particle->SetLifespan(15);
	}
}
