#pragma once
#include "include.h"

class MVShaderManager
{
public:
	void init(const char* vertexShaderPath, const char* fragmentShaderPath);
	void exit();

	void render();

	unsigned int getShaderProgram() { return mShaderProgram; }


	void setBool(const std::string& name, bool value);

	void setInt(const std::string& name, int value);

	void setFloat(const std::string& name, float value);

	void setVec2(const std::string& name, const glm::vec2& value);

	void setVec2(const std::string& name, float x, float y);

	void setVec3(const std::string& name, const glm::vec3& value);

	void setVec3(const std::string& name, float x, float y, float z);

	void setVec4(const std::string& name, const glm::vec4& value);

	void setVec4(const std::string& name, float x, float y, float z, float w);

	void setMat2(const std::string& name, const glm::mat2& mat);

	void setMat3(const std::string& name, const glm::mat3& mat);

	void setMat4(const std::string& name, const glm::mat4& mat);

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

