#include "GravitationalEffector.h"

GravitationalEffector::GravitationalEffector()
{
}

void GravitationalEffector::EffectParticles(Particle* particle)
{
	ofVec3f Direction = (Position - particle->Position);
	Force = Direction.normalize();

	float Strength = Direction.lengthSquared();

	Force *= (this->Strength / Strength);

	particle->AddForce(Force);

}
