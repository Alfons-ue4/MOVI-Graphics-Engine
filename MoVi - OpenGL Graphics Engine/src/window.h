#pragma once

#include "include.h"

class MVWindow
{
public:
	void init(uint32_t width, uint32_t height, std::string title);
	void exit();
	void update();
	bool shouldClose();

	GLFWwindow* getWindow();

private:
	GLFWwindow* mWindow;

};

