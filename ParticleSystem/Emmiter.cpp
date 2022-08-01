#include "Emmiter.h"
#include "ParticleSystem.h"

Emmiter::Emmiter()
{
}

Emmiter::Emmiter(ofVec3f StartPosition)
{
	Position = StartPosition;
}

Particle* Emmiter::GetParticle()
{
	return ParticleSystem::LendParticle();
}

void Emmiter::SetPosition(ofVec3f NewPosition)
{
	Position = NewPosition;
}
