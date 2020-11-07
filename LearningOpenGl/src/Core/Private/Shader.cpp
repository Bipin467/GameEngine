#include "Public/Shader.h"
#include<iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string& filepath)
	:m_FilePath(filepath),m_RendererID(0)
{
	ShaderProgramSource source = ParseShader(filepath);
	m_RendererID = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(m_RendererID));
}

GLuint Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return program;
}

GLuint Shader::CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? " Vertex" : " Fragment") << " Shader" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}
	return id;
}


ShaderProgramSource Shader::ParseShader(const std::string& filePath) {
	std::fstream stream(filePath);
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	ShaderType type = ShaderType::NONE;
	std::string line;
	std::stringstream ss[2];
	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FRAGMENT;
			}
		}
		else {
			ss[(int)type] << line << '\n';
		}

	}
	return{
		ss[0].str(),ss[1].str()
	};
}

void Shader::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void Shader::UnBind() const
{
	GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string name, GLfloat f0, GLfloat f1, GLfloat f2, GLfloat f3)
{
	GLCall(glUniform4f(GetUniformLocation(name), f0, f1, f2, f3));
}

void Shader::SetUniform1f(const std::string name, GLfloat f0) {
	GLCall(glUniform1f(GetUniformLocation(name), f0));
}

void Shader::SetUniform2f(const std::string name, GLfloat f0, GLfloat f1)
{
	GLCall(glUniform2f(GetUniformLocation(name), f0, f1));
}

void Shader::SetUniform1i(const std::string & name, GLint value)
{
	GLCall(glUniform1i(GetUniformLocation(name), value));
}

void Shader::SetUnifromMat4f(const std::string & name, const Mat4& matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name),1, GL_FALSE,matrix.elements));
}

void Shader::SetUnifromMat4f(const std::string & name, const glm::mat4 & matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name),1, GL_FALSE,&matrix[0][0]));
}

GLuint Shader::GetUniformLocation(const std::string name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end()) {
		return m_UniformLocationCache[name];
	}
	GLCall(GLint location = glGetUniformLocation(m_RendererID, name.c_str()));
	if (location == -1) {
		std::cout << "Warning: uniform '" << name << "' Doesn't exist!" << std::endl;
	}
	m_UniformLocationCache[name] = location;
	return location;
}
