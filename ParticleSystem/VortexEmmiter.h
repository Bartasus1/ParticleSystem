#pragma once
#include "StreamEmmiter.h"

class VortexEmmiter : public StreamEmmiter
{
public:
	VortexEmmiter();

	virtual void Emmit() override;

private:
	float Rotation;
};

