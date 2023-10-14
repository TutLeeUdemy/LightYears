#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "D:/CompleteGameDevSeries04_Cpp/Prj/LightYears/LightYearsGame/assets/";
#endif
}
