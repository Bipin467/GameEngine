#pragma once
#include "Core/Public/Renderer/Camera/Camera.h"
class OrthographicCamera: public Camera{
public:
	float OrthographicSize;
public:
	OrthographicCamera();
	OrthographicCamera(float orthographicSize);
	void Update() override;
};