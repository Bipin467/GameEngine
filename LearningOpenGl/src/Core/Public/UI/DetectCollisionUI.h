#pragma once
#include "Public/Transform.h"
class DetectCollisionUI {
public:
	static bool DetectCollisionOnRectangle(Transform* transform, const Vector2& mousePosition);
	static bool DetectCollisionOnCircle(Transform* transform, const Vector2& mousePosition);

	static Vector2 MouseToScreenPos(const Vector2& mousePosition);
};