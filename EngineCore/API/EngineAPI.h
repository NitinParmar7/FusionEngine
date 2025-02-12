#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

extern "C" {
    // Initializes core systems (logging, ECS, etc.)
    ENGINE_API void Engine_Init();

    // Updates engine systems; dt is the time elapsed since the last update
    ENGINE_API void Engine_Update(float dt);

    // Shuts down and cleans up engine resources
    ENGINE_API void Engine_Shutdown();
}
