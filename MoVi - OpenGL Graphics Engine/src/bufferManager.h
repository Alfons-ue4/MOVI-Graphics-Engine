#pragma once

#include "include.h"

class MVBufferManager
{
public:
	void init(float vertices[]);
	void exit();
	void unbind();

private:
	unsigned int mVertexBuffer;
	void createVertexBuffer(float vertices[]);
	void destroyVertexBuffer();

};

