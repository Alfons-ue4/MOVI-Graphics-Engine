#pragma once
#include "camera.h"
#include "window.h"

class MVInput
{
public:
	void init(MVWindow window, int width, int height, float sensitivity);
	void exit();

	void processInput(bool& running, int& polygonMode, MVCamera& camera, bool capMouse);
	void setSensitivity(float sens);

private:
	MVWindow mWindowC;
	GLFWwindow* mWindow;
	MVCamera mCamera;

	void processKeyboard(bool& running, int& polygonMode, MVCamera& camera);
	void processMouse(MVCamera& camera, mouseXY mousexy);

	bool mFirstMouse = true;
	bool processingMouse = false;
	float mLastX;
	float mLastY;
	float mXOffset;
	float mYOffset;

	int mWindowWidth;
	int mWindowHeight;

	float mSensitivity;
};

