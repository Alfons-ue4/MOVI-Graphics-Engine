#include "bufferManager.h"

void MVBufferManager::init(float vertices[], int size)
{
	createVertexBuffer(vertices, size);

}

void MVBufferManager::exit()
{
	destroyVertexBuffer();
}

void MVBufferManager::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void MVBufferManager::createVertexBuffer(float vertices[], int size)
{
	glGenBuffers(1, &mVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), vertices, GL_STATIC_DRAW);
}

void MVBufferManager::destroyVertexBuffer()
{
	glDeleteBuffers(1, &mVertexBuffer);
}

void MVBufferManager::createElementBuffer(unsigned int indices[], int sizeI)
{
	glGenBuffers(1, &mElementBuffer);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeI * sizeof(int), indices, GL_STATIC_DRAW);
}
