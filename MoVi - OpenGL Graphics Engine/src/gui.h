#pragma once

#include "include.h"

class MVGui
{
public:
	void init(GLFWwindow* window);
	void exit();

	void render();

	void createWindows();

private:
	void createDebugWindow();

};

