#include "SphereCollider.h"

SphereCollider::SphereCollider()
{
}

void SphereCollider::CalculateCollision(Particle* particle)
{
    float DeltaPositionSquared = (Position - particle->Position).lengthSquared();
    float DeltaRadius = Radius + particle->Radius;

    if (DeltaPositionSquared <= (DeltaRadius * DeltaRadius))
    {

        ofVec3f Normal = particle->Position - Position;
        ofVec3f Velocity = particle->Velocity;

        //ofVec3f NewVelocity = Velocity - (2 * Normal * (Velocity * Normal));
        ofVec3f NewVelocity = (Velocity.dot(Normal) / DeltaPositionSquared) * -Normal;

        particle->Velocity = NewVelocity;

    }
}

void SphereCollider::Draw()
{
	ofSetSphereResolution(20);
	ofDrawSphere(Position, Radius);
}
