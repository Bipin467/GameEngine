#include "Public/Renderer/Camera/Camera.h"



Camera::Camera() 
{
	
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return m_ProjectionMatrix;
}

glm::mat4 Camera::GetViewMatrix()
{
	return m_ViewMatrix;
}

void Camera::Update()
{
	ComputeViewMatrix();
}

void Camera::ComputeViewMatrix()
{
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 worldUp(0.f, 1.f, 0.f);
	glm::vec3 camFront(0.f, 0.f, -1.f);
	m_ViewMatrix = glm::lookAt(cameraPos, cameraPos + camFront, worldUp);
}

