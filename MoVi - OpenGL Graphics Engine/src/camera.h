#pragma once
#include "include.h"

class MVCamera
{
public:
	void init(float speed = 5.0f, float fov = 90.0f);

	void update(float deltaTime);

	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void rotatePitch(float rot);
	void rotateYaw(float rot);

	void setCameraSpeed(float newSpeed);

	float getYaw() { return yaw; }
	float getPitch() { return pitch; }

	void setYaw(float nYaw) { yaw = nYaw; }
	void setPitch(float nPitch) { pitch = nPitch; }

	glm::mat4 view();

	float getFov() { return mFov; }
	void setFov(int newFov);

private:
	float mCameraSpeed;
	float mCurrentSpeed;
	float mFov;

	glm::vec3 mCameraPosition = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 mCameraDirection;

	glm::vec3 front;
	float yaw = -90.0f;
	float pitch = 0.0f;

	

	glm::vec3 mCameraForward = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 mCameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 mCameraView;
};

