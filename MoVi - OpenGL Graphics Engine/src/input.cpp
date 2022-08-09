#include "input.h"

void MVInput::init(MVWindow window, int width, int height, float sensitivity)
{
	mSensitivity = sensitivity;
	mWindow = window.getWindow();
	mWindowC = window;
	mWindowWidth = width / 2.0f;
	mWindowHeight = height / 2.0f;
	
}

void MVInput::processInput(bool& running, int& polygonMode, MVCamera& camera, bool capMouse)
{
	processKeyboard(running, polygonMode, camera);
}

void MVInput::setSensitivity(float sens)
{
	mSensitivity = sens;
}

void MVInput::processKeyboard(bool& running, int& polygonMode, MVCamera& camera)
{
	mCamera = camera;
	if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		running = false;
		LINFO("Engine closing")
	}
	if (glfwGetKey(mWindow, GLFW_KEY_F2) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		polygonMode = GL_LINE;
		glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	if (glfwGetKey(mWindow, GLFW_KEY_F1) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		polygonMode = GL_FILL;
		glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	if (glfwGetKey(mWindow, GLFW_KEY_F3) == GLFW_PRESS)
	{
		glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	if (glfwGetKey(mWindow, GLFW_KEY_F4) == GLFW_PRESS)
	{
		glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}


	if (glfwGetKey(mWindow, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera.moveForward();
	}
	if (glfwGetKey(mWindow, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera.moveBackward();
	}
	if (glfwGetKey(mWindow, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera.moveLeft();
	}
	if (glfwGetKey(mWindow, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera.moveRight();
	}
	if (glfwGetKey(mWindow, GLFW_KEY_Q) == GLFW_PRESS)
	{
		camera.moveDown();
	}
	if (glfwGetKey(mWindow, GLFW_KEY_E) == GLFW_PRESS)
	{
		camera.moveUp();
	}

	if (glfwGetMouseButton(mWindow, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
	{
		if (!processingMouse)
		{
			mFirstMouse = true;
			processingMouse = true;
			glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
		processMouse(camera, mWindowC.getMouseXY());
	}
	if (glfwGetMouseButton(mWindow, GLFW_MOUSE_BUTTON_2) == GLFW_RELEASE)
	{
		if (processingMouse)
		{
			processingMouse = false;
			glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

			//glfwGetWindowSize(mWindow, &mWindowWidth, &mWindowHeight);
			//glfwSetCursorPos(mWindow, mWindowWidth / 2, mWindowHeight / 2);
		}
	}
}

void MVInput::processMouse(MVCamera& camera, mouseXY mousexy)
{
	if (!ImGui::GetIO().WantCaptureMouse)
	{
		if (mFirstMouse)
		{
			mLastX = mousexy.xposition;
			mLastY = mousexy.yposition;
			mFirstMouse = false;
		}

		mXOffset = (mousexy.xposition - mLastX) * mSensitivity;
		mYOffset = (mLastY - mousexy.yposition) * mSensitivity;

		mLastX = mousexy.xposition;
		mLastY = mousexy.yposition;

		camera.rotatePitch(mYOffset);
		camera.rotateYaw(mXOffset);
	}

}


