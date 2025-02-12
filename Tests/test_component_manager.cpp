#pragma once
// Tests/test_component_manager.cpp

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "../EngineCore/Source/ECS/PositionData.h"
#include "../EngineCore/Source/ECS/ComponentManager.h"
#include "../EngineCore/Source/ECS/Entity.h"

TEST_CASE("ComponentManager adds and retrieves a Position component", "[ComponentManager]") {
    ComponentManager<Position> posManager;
    Entity testEntity = 1;  // For testing, use a dummy entity ID
    Position pos{ 10.0f, 20.0f };

    posManager.addComponent(testEntity, pos);
    auto retrieved = posManager.getComponent(testEntity);

    REQUIRE(retrieved.has_value());
    REQUIRE(retrieved->get().x == Catch::Approx(10.0f));
    REQUIRE(retrieved->get().y == Catch::Approx(20.0f));
}

TEST_CASE("ComponentManager removes a Position component", "[ComponentManager]") {
    ComponentManager<Position> posManager;
    Entity testEntity = 2;
    Position pos{ 5.0f, 15.0f };

    posManager.addComponent(testEntity, pos);
    REQUIRE(posManager.getComponent(testEntity).has_value());

    posManager.removeComponent(testEntity);
    auto opt = posManager.getComponent(testEntity);
    REQUIRE_FALSE(opt.has_value());
}
