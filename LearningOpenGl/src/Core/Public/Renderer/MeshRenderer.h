#pragma once
#include "MeshFilter.h";
class VertexArray;
class VertexBuffer;
class IndexBuffer;
class VertexBufferLayout;
class Shader;
class GameObject;
namespace mesh {
	class IMeshRenderer {
	public:
		IMeshRenderer() {};
		virtual void Render()=0;
	};

	class MeshRenderer : public IMeshRenderer {
	public:
		GameObject* gameObject;
	public:
		MeshRenderer(const MeshRenderer&) = delete;
		MeshRenderer(MeshFilter* meshFilter);
		void SetMesh(MeshFilter* meshFilter);
		inline MeshFilter* GetMeshFilter() const { return m_MeshFilter; };
		void SetGameObject(GameObject* gameObject);
		void SetShader(Shader* shader);
		void Render() override;
		~MeshRenderer();
		VertexArray* GetVAO() const { return m_Vao; };
		VertexBuffer* GetVBO() const { return m_Vbo; };
		Shader* GetShader() const { return m_Shader; };
		IndexBuffer* GetIBO() const { return m_Ib; };
	private:
		VertexArray* m_Vao;
		VertexBuffer* m_Vbo;
		IndexBuffer* m_Ib;
		Shader* m_Shader;
		MeshFilter* m_MeshFilter;
	};
}