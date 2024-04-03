#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "/home/brett/projects/LightYears-git/LightYearsGame/assets/";
#endif
}
