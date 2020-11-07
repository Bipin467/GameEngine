#include "Public/UI/DetectCollisionUI.h"
#include "Public/Renderer/Screen.h"
#include <math.h>
bool DetectCollisionUI::DetectCollisionOnRectangle(Transform * transform, const Vector2& mousePosition)
{
	Vector2 m_MouseScreenCoordPos = MouseToScreenPos(mousePosition);
	float x = transform->Position.x;
	float y = transform->Position.y;
	Vector2 scale = transform->Scale;
	Vector2 min;
	Vector2 max;
	if (scale.x < 0) {
		scale.x *= -1;
	}
	if (scale.y < 0) {
		scale.y *= -1;
	}
	min.x = x - 0.5f*scale.x;
	min.y = y - 0.5f*scale.y;
	max.x = x + 0.5f*scale.x;
	max.y = y + 0.5f*scale.y;
	float tempx = max.x - m_MouseScreenCoordPos.x;
	float tempy = max.y - m_MouseScreenCoordPos.y;
	x = m_MouseScreenCoordPos.x - min.x;
	y = m_MouseScreenCoordPos.y - min.y;
	return !(x * tempx < 0 || y * tempy < 0);
}

bool DetectCollisionUI::DetectCollisionOnCircle(Transform * transform, const Vector2& mousePosition)
{
	Vector2 deviceCoord = MouseToScreenPos(mousePosition);
	float radius = pow(transform->Position.x - deviceCoord.x, 2);
	radius += pow(transform->Position.y - deviceCoord.y, 2);
	radius = pow(radius, 0.5f);
	radius = transform->Scale.x * 0.5f - radius;
	return radius>=0;
}

Vector2 DetectCollisionUI::MouseToScreenPos(const Vector2 & mousePosition)
{
	return Vector2(((mousePosition.x / Screen::Width) - 0.5f) * 2, (((Screen::Height - mousePosition.y) / Screen::Height) - 0.5f) * 2);
}
