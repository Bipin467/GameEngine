#pragma once
#include "Core/Engine.h"
//#include "Public/GameObject.h"
class MoveTexture : public GameObject {
private:
	Vector2 m_MousePosition;
	Vector2 m_Offset;
	Vector2 m_MouseScreenCoordPos;
	bool m_Clicked = false;
	bool m_Selected = false;
public:
	void Update() override;
private:
	Vector2 MouseToScreenPos(const Vector2& mousePosition);
	bool CheckCollision();
};