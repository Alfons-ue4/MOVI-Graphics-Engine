#include "vertexAttributeManager.h"

void MVVertexAttributeManager::init()
{
	createVertexArray();
}

void MVVertexAttributeManager::exit()
{
	glDeleteVertexArrays(1, &mVertexArray);
}

void MVVertexAttributeManager::enable()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void MVVertexAttributeManager::bind()
{
	glBindVertexArray(mVertexArray);
}

void MVVertexAttributeManager::unBind()
{
	glBindVertexArray(0);
}

void MVVertexAttributeManager::createVertexArray()
{
	glGenVertexArrays(1, &mVertexArray);
}

void MVVertexAttributeManager::render()
{
	glBindVertexArray(mVertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
