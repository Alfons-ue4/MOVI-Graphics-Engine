#include "renderer.h"

void MVRenderer::render(int p, int v)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(p);
	glBindVertexArray(v);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void MVRenderer::setBackgroundColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
}
