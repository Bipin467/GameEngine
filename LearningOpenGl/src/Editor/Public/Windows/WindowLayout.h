#pragma once
#include "Core/Engine.h"
class WindowLayout {
private:
	Vector2 m_ActualWindowStartPos;
	Vector2 m_ActualWindowSize;
	Vector2 m_PreferredWindowSize;
public:
	WindowLayout(const Vector2& actualWindowStartPos, const Vector2& actualWindowSize, const Vector2& preferredWindowSize);
	WindowLayout(const Vector2& actualWindowStartPos, const Vector2& actualWindowSize);
};