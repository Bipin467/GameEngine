#pragma once
#include <string>
#include "Public/CustomTemplate.h"
class Vector3;
class Vector2;
namespace mesh {

	namespace MeshPrimitives {
		enum class PrimitiveMeshTypes {
			Plane = 0
		};
		class Plane {
		public:
			static Array<Vector3>* GetVertexPosition();
			static Array<unsigned int>* GetIndices();
			static Array<Vector2>* GetUV();
			static Array<Vector3>* GetNormal();
		};
	};

	class IMeshFilter {
	public:
		IMeshFilter() {};
		virtual void LoadOperation() {};
	};

	class Mesh{
	private :
		Array<Vector3>* m_VertexPosition;
		Array<unsigned int>* m_Indices;
		Array<Vector2>* m_UV;
		Array<Vector3>* m_Normal;
	public:
		Mesh(Array<Vector3>* vertexPositions,Array<unsigned int>* indices, Array<Vector2>* uv, Array<Vector3>* normal)
			: m_VertexPosition(vertexPositions),m_Indices(indices), m_UV(uv), m_Normal(normal) {};
		Mesh() :m_VertexPosition(nullptr), m_UV(nullptr), m_Normal(nullptr) {};
		~Mesh();
		inline Array<Vector3>* GetVertexPosition() const { return m_VertexPosition; };
		inline Array<Vector2>* GetUV() const {return m_UV;};
		inline Array<Vector3>* GetNormals() const { return m_Normal; };
		inline Array<unsigned int>* GetIndices() const { return m_Indices; };
	};

	class MeshFilter:IMeshFilter {
	private:
		Mesh* m_Mesh;
	public:
		MeshFilter(const std::string& fileLocation);
		MeshFilter(MeshPrimitives::PrimitiveMeshTypes type);
		Mesh* GetMesh() { return m_Mesh; };
	};



}