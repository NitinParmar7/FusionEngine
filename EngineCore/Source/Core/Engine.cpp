#pragma once

#include "pch.h"
#include "EngineAPI.h"
#include <iostream>
#include <format>
#include <Logger/Logger.h>

// Example subsystem stubs (e.g., logging, ECS, job system, etc.)
namespace EngineCore {
    void Init() {

       Logger::Instance().SetOutputFile("log.txt");
       LOG_INFO("[EngineCore] system initializing...")
        // Initialize logging, event systems, ECS, etc.
    }

    void Update(float dt) {
        // Update core subsystems (physics, game logic, rendering calls, etc.)
       LOG_INFO("[EngineCore] Updating systems with dt = {}", dt);
    }

    void Shutdown() {
        // Clean up all initialized subsystems
        LOG_INFO("[EngineCore] Shutting down engine core systems...");
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
