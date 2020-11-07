#include "Public/Input.h"

Input* Input::m_instance;
Input & Input::GetInstance()
{
	m_instance == nullptr ? m_instance = new Input() : m_instance;
	return *m_instance;
}

Input::Input() {
}

void Input::RegisterKeystate(KeyCode key) {
	this->m_InputKeyState[key] = KeyState::NONE;
}

void Input::ChangeKeyState(KeyCode key, KeyState state)
{
	this->m_InputKeyState[key] = state;
}



void  Input::RegisterKeyEventCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	this->ChangeKeyState((KeyCode)key, (KeyState)action);
}

void Input::RegisterMousePositionCallbackGLFW(GLFWwindow * window, double xPos, double yPos)
{
	Input::GetInstance().RegisterMousePositionCallback(window, xPos, yPos);
}

void Input::RegisterMousePositionCallback(GLFWwindow * window, double xPos, double yPos)
{
	m_MousePosition.x = (float)xPos;
	m_MousePosition.y = (float)yPos;
}

void Input::RegisterMouseButtonCallbackGLFW(GLFWwindow * window, int button, int action, int mods)
{
	Input::GetInstance().RegisterMouseButtonCallback(window, button, action, mods);
}

void Input::RegisterMouseButtonCallback(GLFWwindow * window, int button, int action, int mods)
{
	m_MouseButtonState = (MouseButtonState)action;
	m_MouseButton = (MouseButton)button;
}

void Input::RegisterScrollOffsetGLFW(GLFWwindow * window, double xOffset, double yOffset)
{
	GetInstance().RegisterScrollOffset(window, xOffset, yOffset);
}

void Input::RegisterScrollOffset(GLFWwindow * window, double xOffset, double yOffset)
{
	m_ScrollOffset.x = (float)xOffset;
	m_ScrollOffset.y = (float)yOffset;
}

bool Input::GetKeyDown(KeyCode k)
{
	if (this->m_InputKeyState.find(k) != m_InputKeyState.end()) {
		return this->m_InputKeyState.at(k) == KeyState::DOWN;
	}
	this->RegisterKeystate(k);
	return false;
}

bool Input::GetKey(KeyCode k)
{
	if (this->m_InputKeyState.find(k) != m_InputKeyState.end()) {
		return this->m_InputKeyState.at(k) == KeyState::PRESSED;
	}
	this->RegisterKeystate(k);
	return false;
}

void Input::RefreshInput() {
	for (auto x : m_InputKeyState) {
		if (m_InputKeyState[x.first] == KeyState::DOWN) {
			m_InputKeyState[x.first] = KeyState::PRESSED;
		}
		else if(m_InputKeyState[x.first] == KeyState::UP){
			m_InputKeyState[x.first] = KeyState::NONE;
		}
	}
	if (m_MouseButtonState == MouseButtonState::UP) {
		m_MouseButtonState = MouseButtonState::NONE;
		m_MouseButton = MouseButton::NONE;
	}
	m_ScrollOffset = Vector2::Zero();
}

Vector2 Input::GetMousePosition()
{
	return m_MousePosition;
}

Vector2 Input::GetMousePositionLocal()
{
	return m_MousePosition;
}

Vector2 Input::GetMousePositionGlobal()
{
	return m_MousePosition;
}

bool Input::GetKeyUp(KeyCode k)
{
	if (this->m_InputKeyState.find(k) != m_InputKeyState.end()) {
		return this->m_InputKeyState[k] == KeyState::UP;
	}
	this->RegisterKeystate(k);
	return false;
}

bool Input::GetMouseButtonDown(MouseButton m)
{
	return m == m_MouseButton && m_MouseButtonState == MouseButtonState::DOWN;
}

bool Input::GetMouseButtonUp(MouseButton m)
{
	return m == m_MouseButton && m_MouseButtonState == MouseButtonState::UP;
}

void Input::RegisterKeyEventCallbackGLFW(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Input::GetInstance().RegisterKeyEventCallback(window, key, scancode, action, mods);
}
