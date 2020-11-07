#pragma once
#include "Public/Assertion.h"

class VertexBuffer {
private:
	GLuint m_RendererId;
public:
	VertexBuffer(const void* data, GLuint size);
	~VertexBuffer();
	void Bind() const;
	void Unbind() const;
};