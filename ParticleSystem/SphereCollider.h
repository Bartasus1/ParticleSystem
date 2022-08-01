#pragma once
#include "Collider.h"
class SphereCollider : public Collider
{
public:
	SphereCollider();

	float Radius = 400;

	virtual void CalculateCollision(Particle* particle) override;
	virtual void Draw() override;
};

