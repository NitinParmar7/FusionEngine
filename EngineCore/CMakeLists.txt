# EngineCore/CMakeLists.txt

# Collect all source files recursively.
file(GLOB_RECURSE ENGINE_CORE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.h"
)

# Organize files in Visual Studio based on their folder structure.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/Source 
             PREFIX "Source" 
             FILES ${ENGINE_CORE_SOURCES})

# Add the library target and include the sources.
add_library(EngineCore SHARED ${ENGINE_CORE_SOURCES})


# Define ENGINE_EXPORTS so that functions are exported.
target_compile_definitions(EngineCore PRIVATE ENGINE_EXPORTS)

# Specify include directories so that any project linking against EngineCore can use it's headers.
target_include_directories(EngineCore PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/API
	${CMAKE_CURRENT_SOURCE_DIR}/Source
	${CMAKE_CURRENT_SOURCE_DIR}/Source/Core
)