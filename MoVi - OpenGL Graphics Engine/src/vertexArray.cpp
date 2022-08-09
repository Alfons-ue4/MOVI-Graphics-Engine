#include "vertexArray.h"

void MVVertexArray::init()
{
	createVertexArray();
}

void MVVertexArray::exit()
{
	glDeleteVertexArrays(1, &mVertexArray);
}

void MVVertexArray::render()
{
	glBindVertexArray(mVertexArray);
}

void MVVertexArray::unbind()
{
	glBindVertexArray(0);
}

void MVVertexArray::setAttrib()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void MVVertexArray::createVertexArray()
{
	glGenVertexArrays(1, &mVertexArray);
	glBindVertexArray(mVertexArray);
}

