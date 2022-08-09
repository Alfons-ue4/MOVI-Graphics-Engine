#include "camera.h"

void MVCamera::init(float speed, float fov)
{
	mCameraSpeed = speed;
	mFov = fov;
}

void MVCamera::update(float deltaTime)
{
	mCurrentSpeed = mCameraSpeed * deltaTime;
}

void MVCamera::moveForward()
{
	mCameraPosition += mCurrentSpeed * mCameraForward;
}

void MVCamera::moveBackward()
{
	mCameraPosition -= mCurrentSpeed * mCameraForward;
}

void MVCamera::moveLeft()
{
	mCameraPosition -= glm::normalize(glm::cross(mCameraForward, mCameraUp)) * mCurrentSpeed;
}

void MVCamera::moveRight()
{
	mCameraPosition += glm::normalize(glm::cross(mCameraForward, mCameraUp)) * mCurrentSpeed;
}

void MVCamera::moveUp()
{
	mCameraPosition += mCurrentSpeed * mCameraUp;
}

void MVCamera::moveDown()
{
	mCameraPosition -= mCurrentSpeed * mCameraUp;
}

void MVCamera::rotatePitch(float rot)
{
	pitch += rot;
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
	front.y = sin(glm::radians(pitch));
}

void MVCamera::rotateYaw(float rot)
{
	yaw += rot;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	mCameraForward = glm::normalize(front);
}

void MVCamera::setCameraSpeed(float newSpeed)
{
	mCameraSpeed = newSpeed;
}

glm::mat4 MVCamera::view()
{
	mCameraView = glm::lookAt(mCameraPosition, mCameraPosition + mCameraForward, mCameraUp);
	return mCameraView;
}

void MVCamera::setFov(int newFov)
{
	mFov = newFov;
}
