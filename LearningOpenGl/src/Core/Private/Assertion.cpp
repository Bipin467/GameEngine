#include "Public/Assertion.h";
#include <iostream>;
void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, const int line) {
	while (GLenum error = glGetError()) {
		std::cout << "OpenGl Error {" << std::hex << std::showbase << error << std::dec << std::noshowbase << "}" << " \nin function " << function << " \nfile " << file << " \nLine " << line << std::endl;
		return false;
	}
	return true;
}