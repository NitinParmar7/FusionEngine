#pragma once

#include "pch.h"
#include "EngineAPI.h"
#include <iostream>

// Example subsystem stubs (e.g., logging, ECS, job system, etc.)
namespace EngineCore {
    void Init() {
        std::cout << "[Engine] Core systems initializing..." << std::endl;
        // Initialize logging, event systems, ECS, etc.
    }

    void Update(float dt) {
        // Update core subsystems (physics, game logic, rendering calls, etc.)
        std::cout << "[Engine] Updating systems with dt = " << dt << std::endl;
    }

    void Shutdown() {
        // Clean up all initialized subsystems
        std::cout << "[Engine] Shutting down core systems..." << std::endl;
    }
}

extern "C" {

    ENGINE_API void Engine_Init() {
        EngineCore::Init();
    }

    ENGINE_API void Engine_Update(float dt) {
        EngineCore::Update(dt);
    }

    ENGINE_API void Engine_Shutdown() {
        EngineCore::Shutdown();
    }

} // extern "C"
