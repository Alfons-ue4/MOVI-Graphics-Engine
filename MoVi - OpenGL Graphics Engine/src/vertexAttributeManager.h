#pragma once
#include "include.h"

class MVVertexAttributeManager
{
public:
	void init();
	void exit();
	void enable();
	void bind();
	void unBind();
	void render();

private:
	void createVertexArray();
	

	unsigned int mVertexArray;

};

