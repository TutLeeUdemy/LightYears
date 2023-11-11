#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "/Users/JT/Desktop/dev/LightYears/LightYearsGame/assets/";
#endif
}
