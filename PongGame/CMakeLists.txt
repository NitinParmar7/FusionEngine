# PongGame/CMakeLists.txt
# Create an executable target for the Pong game.
add_executable(PongGame PongGame.cpp)

# Link the PongGame executable to the EngineCore library.
target_link_libraries(PongGame PRIVATE EngineCore)

# Optionally, add include directories if needed.
# (This might not be necessary if EngineCore's public headers are exposed.)
target_include_directories(PongGame PRIVATE
    ${CMAKE_SOURCE_DIR}/EngineCore/API
)