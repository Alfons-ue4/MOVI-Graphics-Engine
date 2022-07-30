#include "bufferManager.h"

void MVBufferManager::init()
{
	createVertexBuffer();
}

void MVBufferManager::exit()
{
	destroyVertexBuffer();
}

void MVBufferManager::bind(float bufferData[])
{
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);
}

void MVBufferManager::unBind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void MVBufferManager::createVertexBuffer()
{
	glGenBuffers(1, &mVertexBuffer);
}

void MVBufferManager::destroyVertexBuffer()
{
	glDeleteBuffers(1, &mVertexBuffer);
}
