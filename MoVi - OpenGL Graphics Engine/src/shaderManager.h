#pragma once
#include "include.h"

class MVShaderManager
{
public:
	void init(std::string vertexShaderPath, std::string fragmentShaderPath);
	void exit();
	void render();

private:
	int mVertexShader;
	int mFragmentShader;
	unsigned int mShaderProgram;

	void createVertexShader(std::string vertexShaderPath);
	void createFragmentShader(std::string fragmentShaderPath);
	void createShaderProgram();

	void deleteShaders();

	bool compileShader(int shader);
	bool linkProgram(int program);

	std::string* readFile(std::string path);

};
