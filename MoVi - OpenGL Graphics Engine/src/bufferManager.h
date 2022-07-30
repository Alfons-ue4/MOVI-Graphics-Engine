#pragma once

#include "include.h"

class MVBufferManager
{
public:
	void init();
	void exit();
	void bind(float bufferData[]);
	void unBind();

private:
	unsigned int mVertexBuffer;
	void createVertexBuffer();
	void destroyVertexBuffer();

};

