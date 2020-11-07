#include "Public/Renderer/MeshRenderer.h"
#include "Public/Renderer/Renderer.h"
#include "Public/Renderer/MeshFilter.h"
#include "Public/Maths.h"
mesh::MeshRenderer::MeshRenderer(MeshFilter* meshFilter)
	:m_Vao(nullptr), m_Ib(nullptr), m_Shader(nullptr), m_MeshFilter(meshFilter)
{
	if (meshFilter) {
		if (!meshFilter->GetMesh()) return;
		m_Vao = new VertexArray();
		VertexBufferLayout layout;
		m_Vao->Bind();
		unsigned int size = meshFilter->GetMesh()->GetNormals()->Size()*3;
		size += meshFilter->GetMesh()->GetVertexPosition()->Size()*3;
		size += meshFilter->GetMesh()->GetUV()->Size()*2;
		float* vArrayData = new float[size];
		Vector3* vertexPos = *(meshFilter->GetMesh()->GetVertexPosition());
		layout.PushFloat(3);
		unsigned int* indices = *meshFilter->GetMesh()->GetIndices();
		Vector2* uvs = *meshFilter->GetMesh()->GetUV();
		layout.PushFloat(2);
		Vector3* normals = *meshFilter->GetMesh()->GetNormals();
		layout.PushFloat(3);
		for (int i = 0,j=0; i < meshFilter->GetMesh()->GetVertexPosition()->Size(); i++) {
			vArrayData[j] = vertexPos[i].x;
			vArrayData[++j] = vertexPos[i].y;
			vArrayData[++j] = vertexPos[i].z;
			vArrayData[++j] = uvs[i].x;
			vArrayData[++j] = uvs[i].y;
			vArrayData[++j] = normals[i].x;
			vArrayData[++j] = normals[i].y;
			vArrayData[++j] = normals[i].z;
			++j;
		}
		m_Vbo = new VertexBuffer(vArrayData, size * sizeof(float));
		m_Vbo->Bind();
		m_Vao->AddBuffer(*m_Vbo, layout);
		m_Ib = new IndexBuffer(indices, meshFilter->GetMesh()->GetIndices()->Size());
		m_Ib->Bind();
		
	}
	
}
void mesh::MeshRenderer::SetMesh(MeshFilter* meshFilter)
{
	m_Vao = new VertexArray();
}


void mesh::MeshRenderer::SetGameObject(GameObject * gameObject)
{
	this->gameObject = gameObject;
}

void mesh::MeshRenderer::SetShader(Shader * shader)
{
	m_Shader = shader;
}

void mesh::MeshRenderer::Render()
{
	Renderer r;
	if (!m_Vao || !m_Ib || !m_Shader || !m_MeshFilter) {
		return;
	}
	r.Draw(*m_Vao, *m_Ib, *m_Shader);
}

mesh::MeshRenderer::~MeshRenderer()
{
	delete m_Vao;
	delete m_Ib;
	delete m_Shader;
	delete m_MeshFilter;
}
