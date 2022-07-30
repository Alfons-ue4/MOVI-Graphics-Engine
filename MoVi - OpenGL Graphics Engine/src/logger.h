#pragma once
#include <spdlog/spdlog.h>

void info(std::string i) 
{ 
	spdlog::info(i);
}

void error(std::string e)
{
	spdlog::error(e);
}