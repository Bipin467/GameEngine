#pragma once
#include "Public/Physics/Physics2D/Physics2D.h"
class Transform;
class RigidBody2D :public Physics {
private:
	Vector2 m_ExternalForce;
public:
	float GravityScale;
	float Mass;
	Vector2 Velocity;
	bool IsKinematic;
	Vector2 CenterOfMass;
	Transform* transform;
public:
	RigidBody2D(Transform* transform);
	~RigidBody2D();
	void PhysicsUpdate() override;
	inline Vector2 GetGravity() { return Gravity; };
	inline Vector2 GetScaledGravity() { return Gravity * GravityScale; }
	void AddForce(const Vector2& force);
};