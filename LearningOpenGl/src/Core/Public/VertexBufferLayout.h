#pragma once
#include <vector>
#include "Public/Assertion.h"
struct VertexBufferElement {
	GLuint type;
	GLuint count;
	GLboolean normalized;
	static GLuint GetSizeOfType(GLuint type) {
		switch (type) {
		case GL_FLOAT: return sizeof(GLfloat);
		case GL_UNSIGNED_INT:return sizeof(GLuint);
		case GL_UNSIGNED_BYTE:return sizeof(GLubyte);
		}
		ASSERT(false);
		return 0;
	}
};


class VertexBufferLayout {
private:
	std::vector<VertexBufferElement> m_Elements;
	GLuint m_Stride;
public:
	VertexBufferLayout() :m_Stride(0) {};

	void PushFloat(GLuint count) {
		m_Elements.push_back({ GL_FLOAT,count,GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}
	void PushUInt(GLuint count) {
		m_Elements.push_back({ GL_UNSIGNED_INT,count,GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}
	void PushUByte(GLuint count) {
		m_Elements.push_back({ GL_UNSIGNED_BYTE,count,GL_TRUE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }
	inline GLuint GetStride() const { return m_Stride; }
};