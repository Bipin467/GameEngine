#include <Core/Engine.h>
#include <Games/TextureMovement.h>
//#define PLATFORM_WINDOWS
void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Screen::WindowSizeCallback(width, height);
}

void MoveY(float* positionArray, int size, int dir) {
	for (int i = 1; i < size; i += 2) {
		positionArray[i] += 0.1f*dir;
	}

}

void MoveX(float* positionArray, int size, int dir) {
	for (int i = 0; i < size; i += 2) {
		positionArray[i] += 0.1f*dir;
	}
}

#ifdef PLATFORM_WINDOWS
int WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	glfwGetWindowSize(window, &Screen::Width, &Screen::Height);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "Error glew not ok " << std::endl;
	}
	//std::cout << glGetString(GL_VERSION) << std::endl;
	{
		MoveTexture* t = new MoveTexture();
		mesh::MeshFilter* mf = new mesh::MeshFilter(mesh::MeshPrimitives::PrimitiveMeshTypes::Plane);
		mesh::MeshRenderer* mr = new mesh::MeshRenderer(mf);
		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.2f, 0.4f, 0.8f, 1.0f);
		Texture texture("res/textures/texture.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);
		float r = 0.05f;
		float inc = 0.05f;
		glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
		glfwSetKeyCallback(window, Input::RegisterKeyEventCallbackGLFW);
		glfwSetCursorPosCallback(window, Input::RegisterMousePositionCallbackGLFW);
		glfwSetMouseButtonCallback(window, Input::RegisterMouseButtonCallbackGLFW);
		glfwSetScrollCallback(window, Input::RegisterScrollOffsetGLFW);
		Renderer renderer;
		mr->SetGameObject(static_cast<GameObject*>(t));
		mr->SetShader(&shader);
		float updatedPos[] = { 0.0f,0.0f };
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			Time::GetInstance();
			std::cout << Time::GetInstance().DeltaTime() << std::endl;
			t->Update();
			renderer.Clear();
			shader.Bind();
			texture.Bind();
			shader.SetUniform2f("u_Scale", t->transform->Scale.x, t->transform->Scale.y);
			shader.SetUniform2f("u_Pos", t->transform->Position.x, t->transform->Position.y);
			shader.SetUniform4f("u_Color", r, 0.4f, 0.8f, 1.0f);
			mr->Render();
			if (r > 1) {
				inc = -Time::GetInstance().DeltaTime();
			}
			else if (r < 0) {
				inc = 0.05f;
			}
			r += Time::GetInstance().DeltaTime();
			glfwSwapBuffers(window);
			Input::GetInstance().RefreshInput();
			glfwPollEvents();
			Time::GetInstance().FrameEnd();
		}
		delete &Input::GetInstance();
	}
	glfwTerminate();
	return 0;
}
#else

int main(void) {
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	glfwGetWindowSize(window, &Screen::Width, &Screen::Height);
	Screen::WindowSizeCallback(Screen::Width, Screen::Height);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cout << "Error glew not ok " << std::endl;
	}
	//std::cout << glGetString(GL_VERSION) << std::endl;
	{
		RenderPipeline rp;
		//Camera c;
		//glm::mat4 mat = glm::ortho(0.0f,16.0f,0.0f,9.0f,-1.0f,1.0f);
		glm::mat4 Projection = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);
		MoveTexture* t = new MoveTexture();
		RigidBody2D* rb = new RigidBody2D(t->transform);
		mesh::MeshFilter* mf = new mesh::MeshFilter(mesh::MeshPrimitives::PrimitiveMeshTypes::Plane);
		mesh::MeshRenderer* mr = new mesh::MeshRenderer(mf);
		Shader shader("res/shaders/Basic.shader");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.2f, 0.4f, 0.8f, 1.0f);
		Texture texture("res/textures/texture.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);
		float r = 0.05f;
		float inc = 0.05f;
		glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
		glfwSetKeyCallback(window, Input::RegisterKeyEventCallbackGLFW);
		glfwSetCursorPosCallback(window, Input::RegisterMousePositionCallbackGLFW);
		glfwSetMouseButtonCallback(window, Input::RegisterMouseButtonCallbackGLFW);
		glfwSetScrollCallback(window, Input::RegisterScrollOffsetGLFW);
		Renderer renderer;
		mr->SetGameObject(static_cast<GameObject*>(t));
		mr->SetShader(&shader);
		rp.RegisterMeshRenderer(static_cast<mesh::IMeshRenderer*>(mr));
		t->SetRigidBody(rb);
		float updatedPos[] = { 0.0f,0.0f };
		float* fp = &t->transform->GetModelMatrix()[0][0];
		for (int i = 0; i < 16; i++) {
			std::cout << *(fp + i) << std::endl;
		}
		float tim = 0;
		float dtmes = 0;
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			//Vector3 pos = t->transform->Position;
			//Vector3 rot = t->transform->Rotation;
			//Vector3 scale = t->transform->Scale;
			//glm::mat4 mvpModel(1.f);
			//mvpModel = glm::translate(mvpModel, glm::vec3(pos.x, pos.y, pos.z));
			//mvpModel = glm::rotate(mvpModel, rot.x*DEGTORAD, glm::vec3(1.f, 0.f, 0.f));
			//mvpModel = glm::rotate(mvpModel, rot.y*DEGTORAD, glm::vec3(0.f, 1.f, 0.f));
			//mvpModel = glm::rotate(mvpModel, rot.z*DEGTORAD, glm::vec3(0.f, 0.f, 1.f));
			//mvpModel = glm::scale(mvpModel, glm::vec3(scale.x, scale.y, scale.z));
			//GLCall(glEnable(GL_SCISSOR_TEST));
			//GLCall(glScissor(0, 0, Screen::Width / 2, Screen::Height / 2));
			Time::GetInstance();
			tim += Time::DeltaTime();
			dtmes = (dtmes + Time::DeltaTime()) / 2.0f;
			if (tim > 1) {
				std::cout << 1 / dtmes << " fps\n";
				tim = 0;
			}
			glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::vec3 worldUp(0.f, 1.f, 0.f);
			glm::vec3 camFront(0.f, 0.f, -1.f);
			glm::mat4 view(1.f);
			view = glm::lookAt(cameraPos, cameraPos + camFront, worldUp);
			Mat4 MVP = Projection * view* t->transform->GetModelMatrix();
			rb->PhysicsUpdate();
			t->Update();
			renderer.Clear();
			shader.Bind();
			texture.Bind();
			shader.SetUniform4f("u_Color", r, 0.4f, 0.8f, 1.0f);
			shader.SetUnifromMat4f("u_MVP", MVP);
			rp.Render();
			//GLCall(glDisable(GL_SCISSOR_TEST));
			//GLCall(glFinish());
			if (r > 1) {
				inc = -0.05f;
			}
			else if (r < 0) {
				inc = 0.05f;
			}
			r += inc;
			glfwSwapBuffers(window);
			Input::GetInstance().RefreshInput();
			glfwPollEvents();
			Time::GameLoopEnd();
		}
		delete &Input::GetInstance();
	}
	glfwTerminate();
	return 0;
}
#endif