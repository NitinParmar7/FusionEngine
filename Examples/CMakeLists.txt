# Examples/CMakeLists.txt
cmake_minimum_required(VERSION 3.30)
project(Examples)

# Add an executable for the dummy example.
add_executable(DummyExample
    DummyMovementSystem.cpp
    main.cpp)

# Include directories for your engine core ECS, if needed.
target_include_directories(DummyExample PRIVATE
    ${CMAKE_SOURCE_DIR}/EngineCore/Source
)

# Link the DummyExample executable to the EngineCore library.
target_link_libraries(DummyExample PRIVATE EngineCore)

# Copy EngineCore.dll to the output directory of PongGame after building.
add_custom_command(TARGET DummyExample POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_if_different
       $<TARGET_FILE:EngineCore>
       $<TARGET_FILE_DIR:DummyExample>
)


# If DummyMovementSystem depends on other engine core libraries, link them here.
# For example, if you had a library target for EngineCore:
# target_link_libraries(DummyExample PRIVATE EngineCore)

# Create a static library for example systems.
add_library(ExampleSystems STATIC
    DummyMovementSystem.cpp  # Your implementation file for DummyMovementSystem
)

# Include directories for DummyMovementSystem.
target_include_directories(ExampleSystems PUBLIC
    ${CMAKE_SOURCE_DIR}/EngineCore/Source # If DummyMovementSystem depends on ECS headers.
    ${CMAKE_SOURCE_DIR}/Examples              # If DummyMovementSystem.h is here.
)

# Link with EngineCore if DummyMovementSystem depends on it.
target_link_libraries(ExampleSystems PRIVATE EngineCore)