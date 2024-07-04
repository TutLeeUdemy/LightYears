#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "/home/jingtian/dev/LightYears/LightYearsGame/assets/";
#endif
}
