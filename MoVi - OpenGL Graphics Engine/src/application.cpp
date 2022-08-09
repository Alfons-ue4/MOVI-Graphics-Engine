#include "application.h"


void MVApplication::run()
{
	LINFO("Engine starting")

	//initializing stuff
	mWindow.init(srcWidth, srcHeight, mTitle);

	loadGLAD();

	glEnable(GL_DEPTH_TEST);

	mShaderManager.init("src/shaders/vertexShader.vert", "src/shaders/fragmentShader.frag");
	mCamera.init();
	mVertexArray.init();
	mBufferManager.init(mVertices, sizeof(mVertices) / sizeof(mVertices[0]));
	mVertexArray.setAttrib();
	mInput.init(mWindow, srcWidth, srcHeight, 0.1f);
	mGui.init(mWindow.getWindow());
	
	mRenderer.setBackgroundColor(0.2f, 0.2f, 0.2f);

	mShaderManager.render(); //has to render once in order for it to find the uniform
	int tex = mTextureManager.loadTexture("../resources/test.png");
	mShaderManager.setInt("texture1", 0);

	while (!mWindow.shouldClose() && mRunning)
	{
		newFrame();

		mCamera.update(mDeltaTime);

		mInput.processInput(mRunning, mPolygonMode, mCamera, mGui.wantMouse());
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mGui.render();

		mShaderManager.render();
		mTextureManager.render(tex);
		mVertexArray.render();

		glm::mat4 model = glm::mat4(1.0f);
		mShaderManager.setMat4("modelTransform", model);

		glm::mat4 projection = glm::perspective(glm::radians(mCamera.getFov()), (float)srcWidth / (float)srcHeight, 0.1f, 100.0f);
		mShaderManager.setMat4("projection", projection);

		glm::mat4 view = mCamera.view();
		mShaderManager.setMat4("view", view);


		mRenderer.render(mVertexArray.getVertexArray());

		//gui
		mGui.createWindows();
		mRenderer.setBackgroundColor(mGui.bgColor[0], mGui.bgColor[1], mGui.bgColor[2]);
		mCamera.setCameraSpeed(mGui.cameraSpeed * 0.5);
		mInput.setSensitivity(mGui.sensitivity*0.01f);
		mCamera.setFov(mGui.cameraFov);

		mWindow.update();
	}

	//exiting stuff
	mVertexArray.exit();
	mBufferManager.exit();
	mShaderManager.exit();
	mWindow.exit();
	mGui.exit();

	LINFO("Engine closing")

}

void MVApplication::newFrame()
{
	mCurrentFrame = static_cast<float>(glfwGetTime());
	mDeltaTime = mCurrentFrame - mLastFrame;
	mLastFrame = mCurrentFrame;
}

void MVApplication::loadGLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		LERROR("Failed to load glad!")
	}
}
