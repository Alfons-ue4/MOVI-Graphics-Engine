#include "application.h"


void MVApplication::run()
{
	LINFO("Engine starting")

	//initializing stuff
	mWindow.init(srcWidth, srcHeight, mTitle);

	loadGLAD();

	mShaderManager.init("src/shaders/vertexShader.vert", "src/shaders/fragmentShader.frag");

	mVertexArray.init();
	mBufferManager.init(mIndices, mVertices, 6*4 /* sizeof(mVertices) / sizeof(mVertices[0]) */ , 6/*sizeof(mIndices) / sizeof(mIndices[0]) */ );
	mVertexArray.setAttrib();
	mImgui.init(mWindow.getWindow());

	mRenderer.setBackgroundColor(0.2f, 0.2f, 0.2f);

	while (!mWindow.shouldClose() && mRunning)
	{
		handleInput();
		
		glClear(GL_COLOR_BUFFER_BIT);

		mImgui.render();

		mShaderManager.render();
		mVertexArray.render();
		mRenderer.render(mVertexArray.getVertexArray());

		mImgui.createWindows();
		
		mWindow.update();
	}

	//exiting stuff
	mVertexArray.exit();
	mBufferManager.exit();
	mShaderManager.exit();
	mWindow.exit();
	mImgui.exit();

	LINFO("Engine closing")

}

void MVApplication::handleInput()
{
	if (glfwGetKey(mWindow.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		mRunning = false;
		LINFO("Engine closing")
	}
	if (glfwGetKey(mWindow.getWindow(), GLFW_KEY_F2) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		mPolygonMode = GL_LINE;
	}
	if (glfwGetKey(mWindow.getWindow(), GLFW_KEY_F1) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mPolygonMode = GL_FILL;
	}
}

void MVApplication::loadGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		LERROR("Failed to load glad!")
	}
}
