#pragma once
#include "Emmiter.h"

class StreamEmmiter : public Emmiter
{
public:
	StreamEmmiter();

	void SetDirection(ofVec3f NewDirection);

	virtual void Emmit() override;

protected:
	ofVec3f Direction = { 0,1,0 };

	float Velociy = 3;
	float VelocityVariation = 2;
	float PositionVariation = 8;
};

