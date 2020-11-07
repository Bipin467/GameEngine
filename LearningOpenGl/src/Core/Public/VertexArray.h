#pragma once
#include "Public/VertexBuffer.h"
#include "Public/VertexBufferLayout.h"
class VertexArray {
private:
	GLuint m_RendererID;
public:
	VertexArray();
	~VertexArray();
	void Bind() const;
	void UnBind() const;
	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
};