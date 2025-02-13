#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "../EngineCore/Source/ECS/EntityManager.h"
#include "../EngineCore/Source/ECS/PositionData.h"
#include "../EngineCore/Source/ECS/ComponentManager.h"
#include "../EngineCore/Source/ECS/SystemManager.h"
#include "../Examples/DummyMovementSystem.h"



TEST_CASE("DummyMovementSystem updates Position component", "[SystemManager]") {
    // Set up ECS components.
    EntityManager entityManager;
    ComponentManager<Position> posManager;
    SystemManager systemManager;

    // Create an entity and assign a Position.
    Entity e = entityManager.createEntity();
    posManager.addComponent(e, Position{ 0.0f, 0.0f });

    // Register a DummyMovementSystem.
    auto* movementSystem = systemManager.registerSystem<DummyMovementSystem>(posManager);
    movementSystem->entities.push_back(e);

    // Call update with a delta time.
    float dt = 1.0f; // 1 second
    systemManager.updateAll(dt);

    // Check if the position was updated (x increased by 1.0).
    auto opt = posManager.getComponent(e);
    REQUIRE(opt.has_value());
    REQUIRE(opt->get().x == Catch::Approx(1.0f));
    REQUIRE(opt->get().y == Catch::Approx(0.0f)); // y should remain unchanged.
}
