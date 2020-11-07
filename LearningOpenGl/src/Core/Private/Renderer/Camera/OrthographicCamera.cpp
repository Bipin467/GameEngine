#include "Core/Public/Renderer/Camera/OrthoGraphicCamera.h"

OrthographicCamera::OrthographicCamera() {
	m_CameraType = CameraType::Orthographic;
	m_ProjectionMatrix = glm::ortho(1.0f, -1.0f, -(1.0f / Screen::CurrentRenderingWindowResolution), 1.0f / Screen::CurrentRenderingWindowResolution, -1.0f, 1.0f);
	m_ViewPortRectOrigin = glm::vec2(.0f, .0f);
	m_ViewPortRectSize = glm::vec2(1.0f, 1.0f);
	m_FarClippingPlane = -1;
	m_NearClippingPlane = 1;
}

OrthographicCamera::OrthographicCamera(float orthoGraphicSize) {
	m_CameraType = CameraType::Orthographic;
	m_ProjectionMatrix = glm::ortho(1.0f*orthoGraphicSize, -1.0f*orthoGraphicSize, -(1.0f / Screen::CurrentRenderingWindowResolution)*orthoGraphicSize, (1.0f / Screen::CurrentRenderingWindowResolution)*orthoGraphicSize, -1.0f, 1.0f);
	m_ViewPortRectOrigin = glm::vec2(.0f, .0f);
	m_ViewPortRectSize = glm::vec2(1.0f, 1.0f);
	m_FarClippingPlane = -1;
	m_NearClippingPlane = 1;
}

void OrthographicCamera::Update() {

}