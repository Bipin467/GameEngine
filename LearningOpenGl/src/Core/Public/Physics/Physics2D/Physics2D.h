#pragma once
#include "Public/Maths.h"
class Physics {
public:
	int PhysicsID;
	static Vector2 Gravity;
public:
	Physics(){};
	virtual void PhysicsUpdate() {};
};