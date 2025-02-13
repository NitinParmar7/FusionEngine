// Examples/main.cpp
#include <iostream>
#include "DummyMovementSystem.h"
#include "../EngineCore/Source/ECS/Entity.h"
#include "../EngineCore/Source/ECS/EntityManager.h"
#include "../EngineCore/Source/ECS/ComponentManager.h"
#include "../EngineCore/Source/ECS/PositionData.h"

int main() {
    // Create basic ECS components.
    EntityManager entityManager;
    ComponentManager<Position> posManager;

    // Create an entity and add a Position component.
    Entity e = entityManager.createEntity();
    posManager.addComponent(e, Position{ 0.0f, 0.0f });

    // Create a dummy movement system that moves entities.
    DummyMovementSystem movementSystem(posManager);
    // Assume our system operates on all entities; here, we add our single entity.
    movementSystem.entities.push_back(e);

    // Simulate an update (for example, 1 second).
    float dt = 1.0f;
    movementSystem.update(dt);

    // Retrieve updated position.
    auto opt = posManager.getComponent(e);
    if (opt.has_value()) {
        std::cout << "Entity " << e << " new position: ("
            << opt->get().x << ", "
            << opt->get().y << ")\n";
    }
    else {
        std::cout << "Entity " << e << " has no position component!\n";
    }

    return 0;
}
