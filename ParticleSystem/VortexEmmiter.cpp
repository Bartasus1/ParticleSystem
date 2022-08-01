#include "VortexEmmiter.h"

VortexEmmiter::VortexEmmiter()
{
	VelocityVariation = 0;
	PositionVariation = 0;
}

void VortexEmmiter::Emmit()
{
	float RotationRate = 0.2;

	Rotation += RotationRate;
	SetDirection(ofVec3f(cos(Rotation), sin(Rotation), 0));

	__super::Emmit();
}
