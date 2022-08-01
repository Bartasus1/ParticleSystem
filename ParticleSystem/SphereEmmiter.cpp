#include "SphereEmmiter.h"
#include "of3dPrimitives.h"

SphereEmmiter::SphereEmmiter()
{
}

SphereEmmiter::SphereEmmiter(ofVec3f StartPosition) : Emmiter(StartPosition)
{
}

void SphereEmmiter::Emmit()
{
	sphere.setPosition(Position);
	sphere.setRadius(20);
	sphere.setResolution(6);

	auto verts = sphere.getMesh().getVertices();

	for (int i = 0; i < verts.size(); i++)
	{
		if (Particle* particle = GetParticle())
		{
			particle->SetLifespan(0.5);
			particle->Position = verts[i] + Position;
			particle->Velocity = (verts[i] - Position) * 100;
		}
	}
}
