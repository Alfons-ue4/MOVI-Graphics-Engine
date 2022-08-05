#include "input.h"

int MVInput::getKeyPress(GLFWwindow* window)
{
	if (!mPressingKey)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			keyHandle(GLFW_KEY_ESCAPE);
			return GLFW_KEY_ESCAPE;

		if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS)
			keyHandle(GLFW_KEY_F1);
			return GLFW_KEY_F1;

		if (glfwGetKey(window, GLFW_KEY_F2) == GLFW_PRESS)
			keyHandle(GLFW_KEY_F2);
			return GLFW_KEY_F2;

		if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS)
			keyHandle(GLFW_KEY_F3);
			return GLFW_KEY_F3;

	}
	else
	{
		if (glfwGetKey(window, pressedKey) == GLFW_RELEASE)
			mPressingKey = false;
			pressedKey = 0;
	}
}

void MVInput::keyHandle(int key)
{
	mPressingKey = true;
	pressedKey = key;
}
