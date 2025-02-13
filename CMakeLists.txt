# CMakeList.txt (Top - Level)

cmake_minimum_required(VERSION 3.30)
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



# --- Testing Setup Using FetchContent (CMake 3.11+ feature) ---
# FetchContent is a modern CMake module that downloads external content at configuration time.
include(CTest)  # Enable testing support.
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.0   # You can change the version as desired.
)

FetchContent_MakeAvailable(Catch2)


enable_testing()

# Add Subdirectories for your project
add_subdirectory(EngineCore)
add_subdirectory(PongGame)
add_subdirectory(Tests)
add_subdirectory(Examples)





set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PongGame)

# if(WIN32)
  # execute_process(
    # COMMAND cmd /c start "" "${CMAKE_BINARY_DIR}/FusionEngine.sln"
    # WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    # RESULT_VARIABLE result
    # OUTPUT_VARIABLE output
    # ERROR_VARIABLE error_output
  # )
  # message("Attempted to open solution; result: ${result}")
  # if(NOT result EQUAL 0)
    # message(WARNING "Failed to open solution automatically. Error: ${error_output}")
  # endif()
# endif()

if(WIN32)
  add_custom_target(open_solution
    COMMAND cmd /c start "" "${CMAKE_BINARY_DIR}/FusionEngine.sln"
    COMMENT "Automatically opening the Visual Studio solution..."
  )

  # On Windows, use 'cmd /C' to run the command with output redirection.
  add_custom_target(run_tests
    COMMAND cmd /C "${CMAKE_CTEST_COMMAND} --output-on-failure > test_output.log"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    COMMENT "Running tests and saving output to test_output.log"
  )
else()
  # On Unix-like systems, use 'sh -c' for the same effect.
  add_custom_target(run_tests
    COMMAND sh -c "${CMAKE_CTEST_COMMAND} --output-on-failure > test_output.log"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    COMMENT "Running tests and saving output to test_output.log"
  )
endif()

