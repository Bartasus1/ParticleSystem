#include "ParticleSystem.h"
#include "ofGraphics.h"
#include "of3dGraphics.h"
#include "Generator.h"


int ParticleSystem::MaxParticles = 50000;
int ParticleSystem::AliveParticles = 0;

Particle* DefaultParticle = new Particle;

std::vector<std::shared_ptr<Particle>> ParticleSystem::GlobalParticles;
ParticleSystem* ParticleSystem::ParticleSystemInstance;

ParticleSystem::ParticleSystem()
{
}

ParticleSystem* ParticleSystem::GetParticleSystem()
{
	if (ParticleSystemInstance == nullptr)
	{
		ParticleSystemInstance = new ParticleSystem();
	}

	return ParticleSystemInstance;
}

Particle* ParticleSystem::LendParticle()
{
	if (AliveParticles < (MaxParticles - 1))
	{
		Particle* particle = GlobalParticles[AliveParticles].get();
		AliveParticles++;

		return particle;
	}
	else
	{
		AddParticle();
	}

}


void ParticleSystem::AddParticle()
{
	MaxParticles++;
	Particle particle;
	std::cout << "Added particle" << MaxParticles << "\n";
	GlobalParticles.push_back(std::make_shared<Particle>(particle));
}

void ParticleSystem::InitializeParticles()
{

	for (int i = 0; i < MaxParticles; i++)
	{
		GlobalParticles.push_back(std::make_shared<Particle>());

		GlobalParticles[i]->Update();
	}
}

void ParticleSystem::Update()
{
	for (int i = 0; i < AliveParticles; i++)
	{
		GlobalParticles[i]->Update();
		GlobalParticles[i]->AddForce({ 0, -0.5, 0 }); //Gravity

		Generator::effector->EffectParticles(GlobalParticles[i].get()); // ApplyForce

		for (auto& collider : Generator::Colliders)
		{
			if (GlobalParticles[i]->bHasCollisions)
			{
				collider->CalculateCollision(GlobalParticles[i].get());
			}
		}

		

		//kill particle
		if (GlobalParticles[i]->Lifespan < 0)
		{
			GlobalParticles[i]->bHasCollisions = DefaultParticle->bHasCollisions;
			GlobalParticles[i]->Lifespan = DefaultParticle->Lifespan;
			GlobalParticles[i]->Color.a = 1;
			
			std::swap(GlobalParticles[i], GlobalParticles[AliveParticles - 1]);
			AliveParticles--;
		}
	}
	
	std::cout << AliveParticles << "\n";
}

void ParticleSystem::Draw()
{
	for (int i = 0; i < AliveParticles; i++)
	{
		ofSetColor(GlobalParticles[i]->Color);

		ofDrawSphere(GlobalParticles[i]->Position, GlobalParticles[i]->Radius);
	}
}
