# Test/CMakeLists.txt
cmake_minimum_required(VERSION 3.30)
project(ECSTests)

#create an executable for our test
add_executable(ECSTests 
	test_entity.cpp
	test_component_manager.cpp
	test_system_manager.cpp
)


#include directories for out test
target_include_directories(ECSTests PRIVATE
	${CMAKE_SOURCE_DIR}/EngineCore/Source/ECS 
)


# Link against Catch2.
target_link_libraries(ECSTests PRIVATE EngineCore ExampleSystems Catch2::Catch2WithMain)




# Optionally, discover tests so that CTest can run them
include(CTest)
include(Catch)

# Register tests with CTest using Catch2's integration.
# Explicitly include the test discovery module using its full path.
# Include the test discovery module from the new "scripts" folder.
catch_discover_tests(ECSTests)

# Copy EngineCore.dll to the output directory of PongGame after building.
add_custom_command(TARGET ECSTests POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_if_different
       $<TARGET_FILE:EngineCore>
       $<TARGET_FILE_DIR:ECSTests>
)
