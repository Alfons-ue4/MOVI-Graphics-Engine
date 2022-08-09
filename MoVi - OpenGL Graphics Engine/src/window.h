#pragma once

#include "include.h"

struct mouseXY
{
	int xposition;
	int yposition;
};

class MVWindow
{
public:
	void init(uint32_t width, uint32_t height, std::string title);
	void exit();
	void update();
	bool shouldClose();

	mouseXY getMouseXY();

	GLFWwindow* getWindow();

private:
	mouseXY mXY;

	GLFWwindow* mWindow;

};

