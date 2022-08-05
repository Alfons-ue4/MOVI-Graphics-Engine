#include "window.h"

//had to be implimented here :/
void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}



void MVWindow::init(uint32_t width, uint32_t height, std::string title)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


	mWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (mWindow == NULL)
	{
		LERROR("Failed to create window!")
		glfwTerminate();
	}

	glfwMakeContextCurrent(mWindow);
	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);
}

void MVWindow::exit()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}

void MVWindow::update()
{
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}

bool MVWindow::shouldClose()
{
	return glfwWindowShouldClose(mWindow);
}

GLFWwindow* MVWindow::getWindow()
{
	return mWindow;
}


