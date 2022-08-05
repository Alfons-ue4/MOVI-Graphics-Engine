#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <spdlog/spdlog.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define LINFO(i) spdlog::info(i);
#define LERROR(e) spdlog::error(e);