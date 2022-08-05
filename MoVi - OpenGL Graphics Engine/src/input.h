#pragma once
#include <GLFW/glfw3.h>

class MVInput
{
public:
	void init() {}
	void exit() {}

	int getKeyPress(GLFWwindow* window);
private:
	void keyHandle(int key);

	bool mPressingKey = false;
	int pressedKey;
};

