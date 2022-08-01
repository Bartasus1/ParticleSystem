#pragma once
#include "Emmiter.h"


class SphereEmmiter : public Emmiter
{
public:
	SphereEmmiter();
	SphereEmmiter(ofVec3f StartPosition);

	virtual void Emmit() override;

private:
	ofSpherePrimitive sphere;
};

