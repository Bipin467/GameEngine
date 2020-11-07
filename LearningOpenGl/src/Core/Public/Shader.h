#pragma once
#include <string>
#include "Public/Assertion.h"
#include <unordered_map>
#include "Public/Maths.h"
#include <Core/Vendor/glm/glm.hpp>
struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {
private:
	GLuint m_RendererID;
	std::string m_FilePath;
	std::unordered_map<std::string, GLint> m_UniformLocationCache;

public:
	Shader(const std::string& filePath);
	~Shader();
	void Bind() const;
	void UnBind() const;
	void SetUniform4f(const std::string name, GLfloat f0, GLfloat f1, GLfloat f2, GLfloat f3);
	void SetUniform1f(const std::string name, GLfloat f0);
	void SetUniform2f(const std::string name, GLfloat f0, GLfloat f1);
	void SetUniform1i(const std::string& name, GLint value);
	void SetUnifromMat4f(const std::string& name, const Mat4& matrix);
	void SetUnifromMat4f(const std::string& name, const glm::mat4& matrix);
public:
	GLuint CompileShader(unsigned int type, const std::string& source);
	GLuint CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgramSource ParseShader(const std::string& filePath);
	GLuint GetUniformLocation(const std::string name);
};