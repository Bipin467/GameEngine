#include "Public/Renderer/Renderer.h"
#include "GLFW/glfw3.h"
#include <iostream>
void Renderer::Clear()
{
	GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::DisableVsync()
{
	glfwSwapInterval(0);
}


void Renderer::EnableVsync() {
	glfwSwapInterval(1);
}

void Renderer::DisableDepthTest()
{
	GLCall(glDisable(GL_DEPTH_TEST));
}

void Renderer::EnableDepthTest()
{
	GLCall(glEnable(GL_DEPTH_TEST));
}

void Renderer::BlendFunc(GLenum sfactor, GLenum dfactor)
{
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void Renderer::DisableBlend()
{
	GLCall(glDisable(GL_BLEND));
}

void Renderer::EnableBlend()
{
	GLCall(glEnable(GL_BLEND));
}

void Renderer::Draw(const VertexArray & va, const IndexBuffer & ib, const Shader & shader) const
{
	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
