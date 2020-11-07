#include "Public/Renderer/MeshFilter.h"
#include "Public/Maths.h"
Array<Vector3>* mesh::MeshPrimitives::Plane::GetVertexPosition()
{
	Array<Vector3>* arrptr = new Array<Vector3>(4);
	Vector3* vptr = *arrptr;
	vptr[0] = Vector3(-0.5f, -0.5f, 0.0f);
	vptr[1] = Vector3(0.5f, -0.5f,0.0f);
	vptr[2] = Vector3(0.5f, 0.5f,0.0f);
	vptr[3] = Vector3(-0.5f, 0.5f, 0.0f);
	return arrptr;
}

Array<unsigned int>* mesh::MeshPrimitives::Plane::GetIndices()
{
	Array<unsigned int>* intptr = new Array<unsigned int>(6);
	unsigned int* arrs = *intptr;
	arrs[0] = 0;
	arrs[1] = 1;
	arrs[2] = 2;
	arrs[3] = 2;
	arrs[4] = 3;
	arrs[5] = 0;
	return intptr;
}

Array<Vector2>* mesh::MeshPrimitives::Plane::GetUV()
{
	Array<Vector2>* arruvs = new Array<Vector2>(4);
	Vector2* vecptr = *arruvs;
	vecptr[0] = Vector2(0.0f, 0.0f);
	vecptr[1] = Vector2(1.0f, 0.0f);
	vecptr[2] = Vector2(1.0f, 1.0f);
	vecptr[3] = Vector2(0.0f, 1.0f);
	return arruvs;
}

Array<Vector3>* mesh::MeshPrimitives::Plane::GetNormal()
{
	Array<Vector3>* normptr = new Array<Vector3>(4);
	Vector3* arr = *normptr;
	arr[0] = Vector3::Zero();
	arr[1] = Vector3::Zero();
	arr[2] = Vector3::Zero();
	arr[3] = Vector3::Zero();
	return normptr;
}

mesh::Mesh::~Mesh()
{
	delete m_VertexPosition;
	delete m_Indices;
	delete m_UV;
	delete m_Normal;
}

mesh::MeshFilter::MeshFilter(const std::string & fileLocation)
{
}

mesh::MeshFilter::MeshFilter(MeshPrimitives::PrimitiveMeshTypes type)
{
	using namespace MeshPrimitives;
	if (type == MeshPrimitives::PrimitiveMeshTypes::Plane) {
		m_Mesh = new Mesh(Plane::GetVertexPosition(), Plane::GetIndices(), Plane::GetUV(), Plane::GetNormal());
	}
	else {
		m_Mesh = nullptr;
	}
}
