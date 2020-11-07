#pragma once
#include "GLFW/glfw3.h"
#include <unordered_map>
#include "Public/Maths.h"

enum class KeyCode : short {
	SPACE = 32, NUM0 = 48, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9, A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, ESCAPE = 256, ENTER, TAB, BACKSAPCE, INSERT, DELETE, ARROW_RIGHT, ARROW_LEFT, ARROW_DOWN, ARROW_UP, PAGE_UP, PAGE_DOWN, HOME, END, CAPSLOCK = 280, NUMLOCK = 282, F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, NUMPAD0 = 320, NUMPAD1, NUMPAD2, NUMPAD3, NUMPAD4, NUMPAD5, NUMPAD6, NUMPAD7, NUMPAD8, NUMPAD9, SHIFT_LEFT = 340, CTRL_LEFT, ALT_LEFT, COMMANDKEY, SHIFT_RIGHT, CTRL_RIGHT, ALT_RIGHT
};

enum class KeyState :char {
	UP = 0, DOWN, PRESSED, NONE
};

enum class MouseButtonState:char  {
	UP = 0, DOWN, NONE
};

enum class MouseButton:char {
	LEFT = 0, RIGHT, MIDDLE, NONE
};


class Input {
private:
	static Input* m_instance;
	std::unordered_map<KeyCode, KeyState> m_InputKeyState;
	Vector2 m_MousePosition;
	Vector2 m_ScrollOffset;
	MouseButtonState m_MouseButtonState;
	MouseButton m_MouseButton;
private:
	Input();
	void RegisterKeystate(KeyCode key);
	inline void ChangeKeyState(KeyCode key, KeyState state);
public:
	static Input& GetInstance();
	static void RegisterKeyEventCallbackGLFW(GLFWwindow* window, int key, int scancode, int action, int mods);
	void RegisterKeyEventCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void RegisterMousePositionCallbackGLFW(GLFWwindow* window, double xPos, double yPos);
	void RegisterMousePositionCallback(GLFWwindow* window, double xPos, double yPos);
	static void RegisterMouseButtonCallbackGLFW(GLFWwindow* window, int button, int action, int mods);
	void RegisterMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void RegisterScrollOffsetGLFW(GLFWwindow* window, double xOffset, double yOffset);
	void RegisterScrollOffset(GLFWwindow* window, double xOffset, double yOffset);
	bool GetKeyDown(KeyCode k);
	bool GetKey(KeyCode k);
	bool GetKeyUp(KeyCode k);
	bool GetMouseButtonDown(MouseButton m);
	bool GetMouseButtonUp(MouseButton m);
	void RefreshInput();
	inline Vector2 GetScrollOffset() const { return m_ScrollOffset; };
	Vector2 GetMousePosition();
	Vector2 GetMousePositionLocal();
	Vector2 GetMousePositionGlobal();
};