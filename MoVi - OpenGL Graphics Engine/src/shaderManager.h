#pragma once
#include "include.h"

class MVShaderManager
{
public:
	void init(const char* vertexShaderPath, const char* fragmentShaderPath);
	void exit();

	void render();

	void setFloat(const std::string& name, float value);
	void setInt(const std::string& name, int value);
	void setBool(const std::string& name, bool value);

	unsigned int getShaderProgram() { return mShaderProgram; }

private:
	unsigned int mVertexShader;
	unsigned int mFragmentShader;
	unsigned int mShaderProgram;

	void createVertexShader(const char* vertexShaderPath);
	void createFragmentShader(const char* fragmentShaderPath);
	void createShaderProgram();

	void deleteShaders();

	bool compileShader(int shader);
	bool linkProgram(int program);

	std::string readFile(const char* path);

};

