#include "Public/Transform.h"

Transform::Transform(GameObject* gameobj)
{
	Scale = Vector3::One();
	gameObject = gameobj;
	ModelMatrix = glm::mat4(1.f);
}

glm::mat4& Transform::GetModelMatrix()
{
	ModelMatrix = glm::mat4(1.0f);
	ModelMatrix = glm::translate(ModelMatrix, glm::vec3(Position.x, Position.y, Position.z));
	ModelMatrix = glm::rotate(ModelMatrix, Rotation.x*DEGTORAD, glm::vec3(1, 0, 0));
	ModelMatrix = glm::rotate(ModelMatrix, Rotation.y*DEGTORAD, glm::vec3(0, 1, 0));
	ModelMatrix = glm::rotate(ModelMatrix, Rotation.z*DEGTORAD, glm::vec3(0, 0, 1));
	ModelMatrix = glm::scale(ModelMatrix, glm::vec3(Scale.x, Scale.y, Scale.z));
	return ModelMatrix;
}

Transform::~Transform()
{
}

