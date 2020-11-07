#include "Public/Renderer/Screen.h"
int Screen::Height;
int Screen::Width;
float Screen::ScreenRes;
int Screen::CurrentRenderingWindowHeight;
int Screen::CurrentRenderingwindowWidth;
float Screen::CurrentRenderingWindowResolution;

void Screen::WindowSizeCallback(int width, int height)
{
	Height = height;
	Width = width;
	ScreenRes = (float)width / float(height);
}

void Screen::CurrentRenderingWindowSizeCallback(int width, int height) {
	CurrentRenderingwindowWidth = width;
	CurrentRenderingWindowHeight = height;
	CurrentRenderingWindowResolution = (float)width / (float)height;
}
