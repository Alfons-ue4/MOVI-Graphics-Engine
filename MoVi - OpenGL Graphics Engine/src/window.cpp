#include "window.h"

float mouseXpos;
float mouseYpos;

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	mouseXpos = static_cast<float> (xpos);
	mouseYpos = static_cast<float> (ypos);
}

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

	mWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (mWindow == NULL)
	{
		LERROR("Failed to create window!")
		glfwTerminate();
	}

	glfwMakeContextCurrent(mWindow);
	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);
	glfwSetCursorPosCallback(mWindow, mouseCallback);
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

mouseXY MVWindow::getMouseXY()
{
	mXY.xposition = mouseXpos;
	mXY.yposition = mouseYpos;
	return mouseXY(mXY);
}

GLFWwindow* MVWindow::getWindow()
{
	return mWindow;
}


