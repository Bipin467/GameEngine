#pragma once
#include "Public/Maths.h"
class GameObject;
class Transform{
private:
	glm::mat4 ModelMatrix;
public:
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
	GameObject* gameObject;
public:
	Transform(GameObject* gameobj);
	glm::mat4& GetModelMatrix();
	~Transform();
};