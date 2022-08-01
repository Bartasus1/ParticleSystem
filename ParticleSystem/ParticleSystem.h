#pragma once
#include "Particle.h"
#include <memory>
#include <vector>

class ParticleSystem
{

public:
	static ParticleSystem* GetParticleSystem();

	static void Update();
	static void Draw();

	static Particle* LendParticle();
	static void AddParticle();
	static void InitializeParticles();

	static std::vector<std::shared_ptr<Particle>> GlobalParticles;
	
private:
	static int MaxParticles;
	static int AliveParticles;
	
	ParticleSystem();
	static ParticleSystem* ParticleSystemInstance;
	
};

