#pragma once
#include "Public/Renderer/Renderer.h"

class Texture {
private:
	GLuint m_RendererID;
	std::string m_FilePath;
	GLubyte* m_LocalBuffer;
	GLint m_Width, m_Height, m_BPP;
public:
	Texture(const Texture &) = delete;
	Texture &operator=(const Texture &) = delete;
	Texture(const std::string& path);
	~Texture();
	void Bind(GLuint slot = 0) const;
	void Unbind();
	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const{ return m_Height; }
};