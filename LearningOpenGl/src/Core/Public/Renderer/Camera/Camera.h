#pragma once
#include"Core/Public/GameObject.h"
#include "Core/Public/Renderer/MeshRenderer.h"
#include "Core/Public/Renderer/Screen.h"
#include <unordered_map>
#include "Core/Public/Maths.h"

enum class CameraType {
	Orthographic = 0, Perspective
};
class Camera :public GameObject {
public:
	glm::mat4 GetProjectionMatrix();
	glm::mat4 GetViewMatrix();
	virtual void Update();
private:
	void ComputeViewMatrix();
protected:
	Camera();
protected:
	glm::mat4 m_ProjectionMatrix;
	glm::mat4 m_ViewMatrix;
	CameraType m_CameraType;
	glm::vec2 m_ViewPortRectOrigin;
	glm::vec2 m_ViewPortRectSize;
	float m_NearClippingPlane;
	float m_FarClippingPlane;

};