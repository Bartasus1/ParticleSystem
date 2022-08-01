#include "PlaneCollider.h"

PlaneCollider::PlaneCollider()
{
}

void PlaneCollider::CalculateCollision(Particle* particle)
{
	if (particle->Position.y < Position.y)
	{

		particle->Velocity = - particle->Velocity;
	}
}

void PlaneCollider::Draw()
{
	ofPlanePrimitive plane(Size, Size, 4, 4);
	plane.setPosition(Position);
	plane.rotateDeg(90, { 1,0,0 });
	plane.draw();
}
