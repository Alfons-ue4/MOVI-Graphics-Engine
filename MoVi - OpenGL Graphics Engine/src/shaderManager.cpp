#include "shaderManager.h"

void MVShaderManager::init(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	createVertexShader(vertexShaderPath);
	createFragmentShader(fragmentShaderPath);
	
	createShaderProgram();

}

void MVShaderManager::exit()
{
	glDeleteProgram(mShaderProgram);
}

void MVShaderManager::render()
{
	glUseProgram(mShaderProgram);
}

std::string MVShaderManager::readFile(const char* path)
{
	std::ifstream ifs(path);
	if (!ifs.good())
	{
		LERROR("Failed to load file" + std::string (path))
	}

	return std::string(
		std::istreambuf_iterator<char>(ifs), 
		std::istreambuf_iterator<char>());
}

void MVShaderManager::createVertexShader(const char* vertexShaderPath)
{
	std::string temp = readFile(vertexShaderPath);
	const char* vertexShaderCode = temp.c_str();

	mVertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(mVertexShader, 1, &vertexShaderCode, NULL);

	if (!compileShader(mVertexShader))
	{
		LERROR("Failed to compile shader!")
	}
}

void MVShaderManager::createFragmentShader(const char* fragmentShaderPath)
{
	std::string temp = readFile(fragmentShaderPath);
	const char* fragmentShaderCode = temp.c_str();

	mFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(mFragmentShader, 1, &fragmentShaderCode, NULL);

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

	if (!linkProgram(mShaderProgram))
	{
		LERROR("Failed to link program!");
	}

	deleteShaders();
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
	glGetShaderiv(program, GL_LINK_STATUS, &success);
	glValidateProgram(mShaderProgram);
	return success;
}

void MVShaderManager::setFloat(const std::string& name, float value)
{
	glUniform1f(glGetUniformLocation(mShaderProgram, name.c_str()), value);
}

void MVShaderManager::setInt(const std::string& name, int value)
{
	glUniform1i(glGetUniformLocation(mShaderProgram, name.c_str()), value);
}


void MVShaderManager::setBool(const std::string& name, bool value) 
{
	glUniform1i(glGetUniformLocation(mShaderProgram, name.c_str()), (int)value);
}
