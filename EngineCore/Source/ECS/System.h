#pragma once
#include "Entity.h"
#include <vector>
#include "EngineAPI.h"

// Abstract base class for all systems.
class System {
public:
    virtual ~System() = default;

    // Each system must implement an update method that takes the elapsed time.
    virtual void update(float dt) = 0;

    // Optionally, systems may track which entities they operate on.
    // For now, we use a simple vector of entity IDs.
    std::vector<Entity> entities;
};
