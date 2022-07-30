#include "application.h"

void MVApplication::run()
{

	LINFO("Engine starting")

	//initializing stuff
	mWindow.init(srcWidth, srcHeight, "Test Title");
	loadGLAD();
	mShaderManager.init("shaders/vertexShader.vert", "shaders/fragmentShader.frag");

	mVertexAttributeManager.init();
	mBufferManager.init();
	mVertexAttributeManager.bind();
	mBufferManager.bind(mVertices);
	mVertexAttributeManager.enable();

	mBufferManager.unBind();
	mVertexAttributeManager.unBind();


	while (!mWindow.shouldClose() && mRunning)
	{
		//input handle
		//--------------------------------------------------------
		switch (mInput.getKeyPress(mWindow.getWindow()))
		{
		case GLFW_KEY_ESCAPE:
			LINFO("Escape key pressed")
				mRunning = false;
		}
		//--------------------------------------------------------

		mRenderer.render();
		mShaderManager.render();
		mVertexAttributeManager.render();
		mWindow.update();
	}

	//exiting stuff
	mWindow.exit();
	mVertexAttributeManager.exit();
	mBufferManager.exit();
	mShaderManager.exit();

	LINFO("Engine closing")

}

void MVApplication::loadGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		LERROR("Failed to load glad!")
	}
}
