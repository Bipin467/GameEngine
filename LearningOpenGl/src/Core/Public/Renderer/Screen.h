#pragma once
class Screen {
public:
	static int Height;
	static int Width;
	static float ScreenRes;
	static int CurrentRenderingWindowHeight;
	static int CurrentRenderingwindowWidth;
	static float CurrentRenderingWindowResolution;
public:
	static void WindowSizeCallback(int width, int height);
	static void CurrentRenderingWindowSizeCallback(int width, int height);
};