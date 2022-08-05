#include "shaderManager.h"

void MVShaderManager::init(std::string vertexShaderPath, std::string fragmentShaderPath)
{
	createVertexShader(vertexShaderPath);
	createFragmentShader(fragmentShaderPath);
	
	createShaderProgram();

	deleteShaders();
}

void MVShaderManager::exit()
{
	glDeleteProgram(mShaderProgram);
}

std::string& MVShaderManager::readFile(std::string path)
{
	std::ifstream ifs(path);
	std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

	return content;
}

void MVShaderManager::createVertexShader(std::string vertexShaderPath)
{
	const char* vertexShaderCode = readFile(vertexShaderPath).c_str();

	mVertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(mVertexShader, 1, &vertexShaderCode, NULL);

	if (!compileShader(mVertexShader))
	{
		LERROR("Failed to compile shader!")
	}
}

void MVShaderManager::createFragmentShader(std::string fragmentShaderPath)
{
	const char* fragmentShaderSource = readFile(fragmentShaderPath).c_str();

	mFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(mFragmentShader, 1, &fragmentShaderSource, NULL);

	if (!compileShader(mFragmentShader))
	{
		LERROR("Failed to compile shader!")
	}
}

void MVShaderManager::createShaderProgram()
{
	mShaderProgram = glCreateProgram();
	glAttachShader(mShaderProgram, mVertexShader);
	glAttachShader(mShaderProgram, mFragmentShader);

	linkProgram(mShaderProgram);

	deleteShaders();
}

void MVShaderManager::render()
{
	glUseProgram(mShaderProgram);
}

void MVShaderManager::deleteShaders()
{
	glDeleteShader(mVertexShader);
	glDeleteShader(mFragmentShader);
}

bool MVShaderManager::compileShader(int shader)
{
	glCompileShader(shader);
	int  success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	return success;
}

bool MVShaderManager::linkProgram(int program)
{
	int success;
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	glValidateProgram(mShaderProgram);
	return success;
}
