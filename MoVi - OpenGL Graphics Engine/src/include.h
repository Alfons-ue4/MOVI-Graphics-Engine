#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

#include <spdlog/spdlog.h>

#define LINFO(i) spdlog::info(i);
#define LERROR(e) spdlog::error(e);