#include "Public/GameObject.h"
GameObject::GameObject()
{
	transform = new Transform(this);
}

GameObject::~GameObject()
{
	delete m_MeshFilter;
	delete m_MeshRenderer;
	delete transform;
	delete m_RigidBody;
}

void GameObject::SetMeshRenderer(mesh::MeshRenderer * meshRenderer)
{
	m_MeshRenderer = meshRenderer;
}

void GameObject::SetMeshFilter(mesh::MeshFilter * meshFilter)
{
	m_MeshFilter = meshFilter;
}


void GameObject::SetRigidBody(RigidBody2D* rigidBody)
{
	m_RigidBody = rigidBody;
}

RigidBody2D* GameObject::GetRigidBody() {
	return m_RigidBody;
}

