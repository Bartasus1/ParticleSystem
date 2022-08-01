#include "CircleEmmiter.h"
#include "ofPolyline.h"
#include "ParticleSystem.h"

CircleEmmiter::CircleEmmiter()
{
}

CircleEmmiter::CircleEmmiter(ofVec3f StartPosition)
{
	Position = StartPosition;
}

void CircleEmmiter::Emmit()
{
	ofPolyline circle;
	float Radius = ofRandom(30, 70);
	circle.arc(Position, Radius, Radius, 0, 360, 30);

	auto verts = circle.getVertices();

	for (int i = 0; i < verts.size(); i++)
	{
		Particle* particle = GetParticle();
		particle->Position = verts[i];
		particle->Velocity = (verts[i] - Position) * 1;
		particle->SetLifespan(1.5);
		
	}
}
