#pragma once

#include "include.h"

class MVBufferManager
{
public:
	void init(unsigned int indices[], float vertices[], int size, int sizeI);
	void exit();
	void unbind();

private:
	unsigned int mVertexBuffer;
	void createVertexBuffer(float vertices[], int size);
	void destroyVertexBuffer();

	unsigned int mElementBuffer;
	void createElementBuffer(unsigned int indices[], int sizeI);

};

