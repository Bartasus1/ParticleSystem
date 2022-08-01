#pragma once
#include <vector>

#include "Effector.h"
#include "WindEffector.h"
#include "GravitationalEffector.h"

#include "Collider.h"
#include "SphereCollider.h"
#include "PlaneCollider.h"

#include "Emmiter.h"
#include "CircleEmmiter.h"
#include "SphereEmmiter.h"
#include "PointEmmiter.h"
#include "StreamEmmiter.h"
#include "VortexEmmiter.h"


class Generator
{
public:
	static Generator* GetGeneratorInstance();
	
	static std::vector<Emmiter*> Emmiters;
	static std::vector<Collider*> Colliders;
	static Effector* effector;

	static void Setup();
	
	static void Emmit();
	static void DrawColliders();

private:
	Generator();

	static Generator* GeneratorInstance;
};

