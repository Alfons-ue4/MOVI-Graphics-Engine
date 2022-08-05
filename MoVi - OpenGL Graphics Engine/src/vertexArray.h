#pragma once
#include "include.h"

class MVVertexArray
{
public:
	void init();
	void exit();

	void render();

	void unbind();

	void setAttrib();

	unsigned int getVertexArray() { return mVertexArray; }


private:
	void createVertexArray();
	
	unsigned int mVertexArray;

};

