#pragma once
#include "include.h"

class MVVertexAttributeManager
{
public:
	void init();
	void exit();

	void unbind();

	void setLayout();

	unsigned int getVertexArray() { return mVertexArray; }


private:
	void createVertexArray();
	
	unsigned int mVertexArray;

};

