#include "input.h"

int MVInput::getKeyPress(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		return GLFW_KEY_ESCAPE;

	else
	{
		return 0;
	}
}
