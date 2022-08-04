#include "vertexAttributeManager.h"

void MVVertexAttributeManager::init()
{
	createVertexArray();
}

void MVVertexAttributeManager::exit()
{
	glDeleteVertexArrays(1, &mVertexArray);
}

void MVVertexAttributeManager::unbind()
{
	glBindVertexArray(0);
}

void MVVertexAttributeManager::setLayout()
{
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
	glEnableVertexAttribArray(0);
}

void MVVertexAttributeManager::createVertexArray()
{
	glGenVertexArrays(1, &mVertexArray);
	glBindVertexArray(mVertexArray);
}

