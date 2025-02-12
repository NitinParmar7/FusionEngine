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

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PongGame)

if(WIN32)
  execute_process(
    COMMAND cmd /c start "" "${CMAKE_BINARY_DIR}/FusionEngine.sln"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    RESULT_VARIABLE result
    OUTPUT_VARIABLE output
    ERROR_VARIABLE error_output
  )
  message("Attempted to open solution; result: ${result}")
  if(NOT result EQUAL 0)
    message(WARNING "Failed to open solution automatically. Error: ${error_output}")
  endif()
endif()
