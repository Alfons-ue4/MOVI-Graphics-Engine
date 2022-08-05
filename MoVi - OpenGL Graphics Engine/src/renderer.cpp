#include "renderer.h"

void MVRenderer::render(unsigned int v)
{

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

void MVRenderer::setBackgroundColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
}
