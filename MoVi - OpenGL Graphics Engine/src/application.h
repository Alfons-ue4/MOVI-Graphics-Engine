#pragma once

#include "window.h"
#include "input.h"
#include "renderer.h"
#include "shaderManager.h"
#include "bufferManager.h"
#include "vertexArray.h"

class MVApplication
{
public:
	void run();

	const unsigned int srcWidth = 700;
	const unsigned int srcHeight = 400;

private:

	void handleInput();
	int mPolygonMode = GL_FILL;

	std::string mTitle = "MoVi - Graphics Engine";

	float mVertices[3*4] = {
		 0.5f,  0.5f, 0.0f, 
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,  
		-0.5f,  0.5f, 0.0f

	};

	unsigned int mIndices[2 * 3] = { 
			0, 1, 3,   
			1, 2, 3
	};

	bool mRunning = true;

	void loadGLAD();

	MVWindow mWindow;
	MVInput mInput;
	MVRenderer mRenderer;
	MVShaderManager mShaderManager;
	MVVertexArray mVertexArray;
	MVBufferManager mBufferManager;

};

