#pragma once

#include "include.h"

class MVBufferManager
{
public:
	void init(float vertices[], int size);
	void exit();
	void unbind();

private:
	unsigned int mVertexBuffer;
	void createVertexBuffer(float vertices[], int size);
	void destroyVertexBuffer();

	unsigned int mElementBuffer;
	void createElementBuffer(unsigned int indices[], int sizeI);

};

