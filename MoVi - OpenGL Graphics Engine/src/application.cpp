#include "application.h"

void MVApplication::run()
{
	LINFO("Engine starting")

	//initializing stuff
	mWindow.init(srcWidth, srcHeight, "Test Title");

	loadGLAD();

	mVertexAttributeManager.init();
	mBufferManager.init(mVertices);
	mVertexAttributeManager.setLayout();
	mBufferManager.unbind();
	mVertexAttributeManager.unbind();

	mShaderManager.init("shaders/vertexShader.vert", "shaders/fragmentShader.frag");

	mRenderer.setBackgroundColor(1.0f, 0.0f, 0.0f);

	while (!mWindow.shouldClose() && mRunning)
	{
		//input handle
		//--------------------------------------------------------
		//switch (mInput.getKeyPress(mWindow.getWindow()))
		//{
		//case GLFW_KEY_ESCAPE:
		//	LINFO("Escape key pressed")
		//		mRunning = false;
		//}
		//--------------------------------------------------------

		mRenderer.render(mShaderManager.getShaderProgram(), mVertexAttributeManager.getVertexArray());

		mWindow.update();
	}

	//exiting stuff
	mVertexAttributeManager.exit();
	mBufferManager.exit();
	mShaderManager.exit();
	mWindow.exit();

	LINFO("Engine closing")

}

void MVApplication::loadGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		LERROR("Failed to load glad!")
	}
}
