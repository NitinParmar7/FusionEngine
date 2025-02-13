#include "DummyMovementSystem.h"

DummyMovementSystem::DummyMovementSystem(ComponentManager<Position>& posManager)
    : positionManager{posManager}
{
}

void DummyMovementSystem::update(float dt)  {
    // For each entity this system is responsible for, update its position.
    for (Entity entity : entities) {
        auto opt = positionManager.getComponent(entity);
        if (opt.has_value()) {
            auto& pos = opt->get();
            pos.x += 1.0f * dt;  // Simple movement: move right by 1 unit per second.
        }
    }
}
