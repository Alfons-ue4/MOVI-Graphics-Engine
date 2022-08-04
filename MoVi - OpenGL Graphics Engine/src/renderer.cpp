#include "renderer.h"

void MVRenderer::render(int p, int v)
{

	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(p);
	glBindVertexArray(v);

	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void MVRenderer::setBackgroundColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
}
