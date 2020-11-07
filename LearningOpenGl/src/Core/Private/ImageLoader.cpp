#include "Public/ImageLoader.h"


ImageLoader::PNGImage::PNGImage()
{
}
ImageLoader::PNGImage* ImageLoader::PNGImage::m_Instance;

ImageLoader::PNGImage* ImageLoader::PNGImage::GetInstance()
{
	return m_Instance == nullptr ? m_Instance = new PNGImage() : m_Instance;
}
