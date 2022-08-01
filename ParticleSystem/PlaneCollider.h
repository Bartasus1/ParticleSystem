#pragma once
#include "Collider.h"


class PlaneCollider : public Collider
{
public:
	PlaneCollider();

	float Size = 5000;

	virtual void CalculateCollision(Particle* particle) override;
	virtual void Draw() override;
};

