// Examples/main.cpp
#include <iostream>


#include "DummyMovementSystem.h"

#include <SystemManager.h>
#include <EntityManager.h>
#include <JobSystem/JobSystem.h>
#include <Logger.h>

int main() {
    // Create basic ECS components.
    EntityManager entityManager;
    ComponentManager<Position> posManager;

    // Create a system manager.
    SystemManager systemManager;


    DummyMovementSystem* dummyMovementSystem = systemManager.registerSystem<DummyMovementSystem>(posManager);

    // Create an entity and add a Position component.
    Entity e = entityManager.createEntity();
    posManager.addComponent(e, Position{ 0.0f, 0.0f });

    // Assume our system operates on all entities; here, we add our single entity.
    dummyMovementSystem->entities.push_back(e);

    JobSystem jobSystem;

    // Simulate an update (for example, 1 second).
    float dt = 1.0f;

    auto futureResult = jobSystem.submit([&systemManager, dt]() {
        systemManager.updateAll(dt);
    });

    futureResult.get();


    // Retrieve updated position.
    auto posOpt = posManager.getComponent(e);
    if (posOpt.has_value()) {
        auto& pos = posOpt.value().get();
        LOG_INFO("Entity {} new position: ( {} , {})", e, pos.x, pos.y);
    }
    else {
        LOG_INFO("Entity {} has no position component!", e);
    }

    return 0;
}
