# EngineCore/CMakeLists.txt

# Collect all source files recursively.
file(GLOB_RECURSE ENGINE_CORE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

foreach(file ${ENGINE_CORE_SOURCES})
    message(STATUS "Found file: ${file}")
endforeach()

# Add the library target and include the sources.
add_library(EngineCore SHARED ${ENGINE_CORE_SOURCES})


# Define ENGINE_EXPORTS so that functions are exported.
target_compile_definitions(EngineCore PRIVATE ENGINE_EXPORTS)

# Specify include directories so that any project linking against EngineCore can use it's headers.
target_include_directories(EngineCore PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/API
	${CMAKE_CURRENT_SOURCE_DIR}/Source
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/ECS
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Logger
)