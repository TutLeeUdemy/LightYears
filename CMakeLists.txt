cmake_minimum_required(VERSION 3.27.7)

project(LightYears
	VERSION 1.0.0
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)

# creates a variable. 
set(LIGHT_YEARS_ENGINE_TARGET_NAME LightYearsEngine) 
set(LIGHT_YEARS_GAME_TARGET_NAME LightYearsGame) 

add_subdirectory(LightYearsEngine)
add_subdirectory(LightYearsGame)