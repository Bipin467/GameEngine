#pragma once
#include "Public/VertexArray.h"
#include "Public/IndexBuffer.h"
#include "Public/Shader.h"
#include "Public/Assertion.h";
class Renderer {
public:
	static void Clear();
	static void DisableVsync();
	static void EnableVsync();
	static void DisableDepthTest();
	static void EnableDepthTest();
	static void BlendFunc(GLenum sfactor, GLenum dfactor);
	static void DisableBlend();
	static void EnableBlend();
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};