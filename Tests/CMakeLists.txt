# Test/CMakeLists.txt
cmake_minimum_required(VERSION 3.31.5)
project(ECSTests)

#create an executable for our test
add_executable(ECSTests 
	test_entity.cpp
	test_component_manager.cpp
)


#include directories for out test
target_include_directories(ECSTests PRIVATE
	${CMAKE_SOURCE_DIR}/EngineCore/ECS  # Where Entity.h and EntityManager.h are located.
)

# Link against Catch2.
target_link_libraries(ECSTests PRIVATE Catch2::Catch2WithMain)

# Optionally, discover tests so that CTest can run them
include(CTest)
include(Catch)
catch_discover_tests(ECSTests)