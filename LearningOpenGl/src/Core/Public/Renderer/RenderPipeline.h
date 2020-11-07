#pragma once
#include "Public/Renderer/MeshRenderer.h"
#include <unordered_map>
class RenderPipeline {
public:
	RenderPipeline();
	void Render();
	unsigned int RegisterMeshRenderer(mesh::IMeshRenderer* iMeshRenderer);
	bool RemoveMeshRenderer(unsigned int id);
private:
	std::unordered_map<unsigned int, mesh::IMeshRenderer*> m_RenderQueueList;
};