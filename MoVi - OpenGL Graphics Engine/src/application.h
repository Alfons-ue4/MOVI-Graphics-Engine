#pragma once

#include "window.h"
#include "input.h"
#include "renderer.h"
#include "shaderManager.h"
#include "bufferManager.h"
#include "vertexAttributeManager.h"

class MVApplication
{
public:
	void run();

	const unsigned int srcWidth = 700;
	const unsigned int srcHeight = 400;

private:
	bool mRunning = true;

	void loadGLAD();

	MVWindow mWindow;
	MVInput mInput;
	MVRenderer mRenderer;
	MVShaderManager mShaderManager;
	MVVertexAttributeManager mVertexAttributeManager;
	MVBufferManager mBufferManager;


	float mVertices[9] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};

};

