#include "Editor/Public/Windows/WindowLayout.h"

WindowLayout::WindowLayout(const Vector2& actualWindowStartPos, const Vector2& actualWindowSize, const Vector2& preferredWindowSize)
	:m_ActualWindowStartPos(actualWindowStartPos), m_ActualWindowSize(actualWindowSize), m_PreferredWindowSize(preferredWindowSize)
{
	if (actualWindowStartPos.x < 0 || actualWindowStartPos.y < 0) {
		m_ActualWindowSize = Vector2::Zero();
		if (actualWindowSize.x < 0 || actualWindowSize.y < 0) {
			m_ActualWindowSize = Vector2(Screen::Width, Screen::Height);
		}
	}
	if (preferredWindowSize.x < 0 || preferredWindowSize.y < 0) {
		m_PreferredWindowSize = m_ActualWindowSize;
	}
}


WindowLayout::WindowLayout(const Vector2& actualWindowStartPos, const Vector2& actualWindowSize)
	:m_ActualWindowStartPos(actualWindowStartPos), m_ActualWindowSize(actualWindowSize), m_PreferredWindowSize(actualWindowSize)
{
	if (actualWindowStartPos.x < 0 || actualWindowStartPos.y < 0) {
		m_ActualWindowSize = Vector2::Zero();
		if (actualWindowSize.x < 0 || actualWindowSize.y < 0) {
			m_ActualWindowSize = Vector2(Screen::Width, Screen::Height);
			m_PreferredWindowSize = m_ActualWindowSize;
		}
	}
}