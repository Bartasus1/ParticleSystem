#include "WindEffector.h"

WindEffector::WindEffector()
{
}

void WindEffector::EffectParticles(Particle* particle)
{
	Force = Direction * Strength;

	particle->AddForce(Force);
}
