#pragma once
#include "Emmiter.h"
class CircleEmmiter : public Emmiter
{
public:
	CircleEmmiter();
	CircleEmmiter(ofVec3f StartPosition);

	virtual void Emmit() override;
};

