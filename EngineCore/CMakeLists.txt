# EngineCore/CMakeLists.txt
# Create a shared library named EngineCore
add_library(EngineCore SHARED
	Source/Engine.cpp
	Source/Logger/Logger.cpp
)

# Define ENGINE_EXPORTS so that functions are exported.
target_compile_definitions(EngineCore PRIVATE ENGINE_EXPORTS)

# Specify include directories so that any project linking against EngineCore can use it's headers.
target_include_directories(EngineCore PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/API
	${CMAKE_CURRENT_SOURCE_DIR}/Source
)