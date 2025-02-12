# CMakeList.txt (Top - Level)

cmake_minimum_required(VERSION 3.15)
project(FusionEngine)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally, define common compiler options here
if (MSVC)
	add_compile_options(/W4 /WX) # For example, warning level 4 and treat warnings as errors.
else()
	add_compile_options(-Wall -Wextra -Werror)
endif()

# Add Subdirectories for your project
add_subdirectory(EngineCore)
add_subdirectory(PongGame)