#pragma once

#include "include.h"

class MVGui
{
public:
	void init(GLFWwindow* window);
	void exit();

	void render();

	void createWindows();

	float bgColor[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
	float cameraSpeed = 5.0f;
	float sensitivity = 10.0f;
	float cameraFov = 90.0f;

	bool wantMouse();

private:
	void createDebugWindow();
	void createStatWindow();

	std::string mFps;

};

