#include "bufferManager.h"

void MVBufferManager::init(float vertices[])
{
	createVertexBuffer(vertices);
}

void MVBufferManager::exit()
{
	destroyVertexBuffer();
}

void MVBufferManager::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void MVBufferManager::createVertexBuffer(float vertices[])
{
	glGenBuffers(1, &mVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void MVBufferManager::destroyVertexBuffer()
{
	glDeleteBuffers(1, &mVertexBuffer);
}
