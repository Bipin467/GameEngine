#include "Public/Physics/Physics2D/RigidBody2D.h"
#include "Public/Time.h"
#include "Public/Transform.h"


RigidBody2D::RigidBody2D(Transform* transform)
	:GravityScale(.2f), Mass(1),Velocity(Vector2::Zero()),IsKinematic(false),CenterOfMass(Vector2::Zero())
{
	 m_ExternalForce = Vector2::Zero();
	this->transform = transform;
}

RigidBody2D::~RigidBody2D()
{
}

void RigidBody2D::PhysicsUpdate()
{
	if (IsKinematic) {
		Velocity = Vector2::Zero();
		return;
	}
	Velocity += GetGravity()*Time::DeltaTime();
	transform->Position += Velocity * Time::DeltaTime();
}

void RigidBody2D::AddForce(const Vector2 & force)
{
	
}
