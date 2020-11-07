#pragma once
#include "Transform.h"
#include "Public/Renderer/MeshRenderer.h"
#include "Public/Physics/Physics2D/RigidBody2D.h"
class GameObject {
private:
	mesh::MeshFilter* m_MeshFilter;
	mesh::MeshRenderer* m_MeshRenderer;
	RigidBody2D* m_RigidBody;
public:
	GameObject();
	~GameObject();
	virtual void Awake() {};
	virtual void Start() {};
	virtual void Update() {};
	virtual void LateUpdate() {};
	void SetMeshRenderer(mesh::MeshRenderer* meshRenderer);
	void SetMeshFilter(mesh::MeshFilter* meshFilter);
	void SetRigidBody(RigidBody2D* rigidBody);
	RigidBody2D * GetRigidBody();
	inline mesh::MeshRenderer* GetMeshRenderer() const { return m_MeshRenderer; };
	inline mesh::MeshFilter* GetMeshFilter() const { return m_MeshFilter; };
public:
	Transform* transform;
};