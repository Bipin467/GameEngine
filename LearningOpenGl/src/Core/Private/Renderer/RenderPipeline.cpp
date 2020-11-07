#include "Public/Renderer/RenderPipeline.h"
RenderPipeline::RenderPipeline()
{
}
void RenderPipeline::Render()
{
	for (auto x : m_RenderQueueList) {
		x.second->Render();
	}
}

unsigned int RenderPipeline::RegisterMeshRenderer(mesh::IMeshRenderer * iMeshRenderer)
{
	unsigned int size = m_RenderQueueList.size();
	m_RenderQueueList[size] = iMeshRenderer;
	return size;
}

bool RenderPipeline::RemoveMeshRenderer(unsigned int id)
{
	if (m_RenderQueueList.find(id) != m_RenderQueueList.end()) {
		m_RenderQueueList.erase(id);
		return true;
	}
	return false;
}
