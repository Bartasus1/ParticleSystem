#include "Generator.h"
#include "ofGraphics.h"

Generator* Generator::GeneratorInstance;
std::vector<Emmiter*> Generator::Emmiters;
std::vector<Collider*> Generator::Colliders;
Effector* Generator::effector;

Generator* Generator::GetGeneratorInstance()
{
	if (GeneratorInstance == nullptr)
	{
		GeneratorInstance = new Generator();
	}

	return GeneratorInstance;
}

Generator::Generator()
{

}

void Generator::Setup()
{
	effector = new GravitationalEffector();

	//COLLIDERS
	Colliders.push_back(new SphereCollider());
	Colliders[0]->Position = ofVec3f(0, -200, 0);

	Colliders.push_back(new PlaneCollider());
	Colliders[1]->Position = ofVec3f(0, -600, 0);


	//EMMITERS
	Emmiters.push_back(new StreamEmmiter());
	Emmiters[0]->SetPosition(ofVec3f(250, 700, 50));
	dynamic_cast<StreamEmmiter*>(Emmiters[0])->SetDirection({ 0,-1,0 });

	Emmiters.push_back(new StreamEmmiter());
	Emmiters[1]->SetPosition(ofVec3f(-250, 700, 45));
	dynamic_cast<StreamEmmiter*>(Emmiters[1])->SetDirection({ 0,-1,0 });

	Emmiters.push_back(new PointEmmiter());
	Emmiters[2]->SetPosition(ofVec3f(-100, 1000, 0));

	Emmiters.push_back(new PointEmmiter());
	Emmiters[3]->SetPosition(ofVec3f(400, 1200, 0));

	
	ofSpherePrimitive sphere(420 , 3);
	auto verts = sphere.getMesh().getVertices();
	for (auto& vert : verts)
	{
		PointEmmiter* point = new PointEmmiter();
		point->SetPosition(vert + Colliders[0]->Position);
		Emmiters.push_back(point);

	}
}

void Generator::Emmit()
{
	for (auto& emmiter : Emmiters)
	{
		emmiter->Emmit();
	}
}

void Generator::DrawColliders()
{
	for (auto& collider : Colliders)
	{
		ofSetColor(ofColor::white);
		collider->Draw();
	}
}
