#pragma once
#include<GL/glew.h>
#define ASSERT(x) if(!(x)) __debugbreak();
#define GLErrorTest(func) GLClearError();\
		func;\
		ASSERT(GLLogCall(#func,__FILE__,__LINE__))
#ifdef _DEBUG
#define GLCall(func) GLErrorTest(func)
#else
#define GLCall(func) func;
#endif

void GLClearError();
bool GLLogCall(const char* function, const char* file, const int line);