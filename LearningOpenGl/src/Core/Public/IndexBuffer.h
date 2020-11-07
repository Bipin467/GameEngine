#pragma once
#include "Assertion.h";
class IndexBuffer {
private:
	GLuint m_RendererId;
	GLuint m_Count;
public:
	IndexBuffer(const GLuint* data, GLuint count);
	~IndexBuffer();
	void Bind() const;
	void Unbind() const;
	inline GLuint GetCount() const { return m_Count; }
};