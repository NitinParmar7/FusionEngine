# PongGame/CMakeLists.txt

file(GLOB_RECURSE PONG_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
             PREFIX "PongGame"
             FILES ${PONG_SOURCES})

# Create an executable target for the Pong game.
add_executable(PongGame ${PONG_SOURCES})

# Link the PongGame executable to the EngineCore library.
target_link_libraries(PongGame PRIVATE EngineCore)

# Optionally, add include directories if needed.
# (This might not be necessary if EngineCore's public headers are exposed.)
target_include_directories(PongGame PRIVATE
    ${CMAKE_SOURCE_DIR}/EngineCore/API
)

# Copy EngineCore.dll to the output directory of PongGame after building.
add_custom_command(TARGET PongGame POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy_if_different
       $<TARGET_FILE:EngineCore>
       $<TARGET_FILE_DIR:PongGame>
)
