#pragma once
#include <fstream>
#include <string>
#include "Public/CustomTemplate.h"
namespace file {
	class BinaryFileLoader {
	private:
		BinaryFileLoader();
		Array<unsigned char>* ReadBytes();
	public:
		static BinaryFileLoader& GetInstance();
		Array<unsigned int> ReadFourByteArray();
		Array<unsigned short> ReadTwoByteArray();
		Array<unsigned char> ReadOneByteArray();
		std::string ReadString();
		Array<std::string> ReadStringLineArray();

	};
}