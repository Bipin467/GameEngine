#include "Public/FileIO/BinaryFileLoader.h"

file::BinaryFileLoader::BinaryFileLoader()
{
}

file::BinaryFileLoader & file::BinaryFileLoader::GetInstance()
{
	static BinaryFileLoader& fileLoader = *(new BinaryFileLoader());
	return fileLoader;
}

Array<unsigned int> file::BinaryFileLoader::ReadFourByteArray()
{
	return Array<unsigned int>(0);
}

Array<unsigned short> file::BinaryFileLoader::ReadTwoByteArray()
{
	return Array<unsigned short>(0);
}

Array<unsigned char> file::BinaryFileLoader::ReadOneByteArray()
{
	return Array<unsigned char>(0);
}

std::string file::BinaryFileLoader::ReadString()
{
	return std::string();
}

Array<std::string> file::BinaryFileLoader::ReadStringLineArray()
{
	return Array<std::string>(0);
}
