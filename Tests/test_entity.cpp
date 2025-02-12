// Define this macro to have Catch2 generate a main() function.
#include <catch2/catch_test_macros.hpp>


#include "../EngineCore/Source/ECS/Entity.h"
#include "../EngineCore/Source/ECS/EntityManager.h"

TEST_CASE("EntityManager creates unique entities", "[EntityManager]") {
	EntityManager em;
	Entity e1 = em.createEntity();
    [[maybe_unused]] Entity e2 = em.createEntity();


	// REQUIRE is provided by Catch2. It checks that the condition is true.
	REQUIRE(e1 != e2);
	REQUIRE(e1 != INVALID_ENTITY);
	REQUIRE(e2 != INVALID_ENTITY);
}

TEST_CASE("EntityManager recycles destroyed entities", "[EntityManager]") {
    EntityManager em;
    Entity e1 = em.createEntity();
    [[maybe_unused]] Entity e2 = em.createEntity();

    // Destroy one entity.
    em.destroyEntity(e1);

    // Create another entity; if recycling works, it should equal e1.
    Entity e3 = em.createEntity();
    REQUIRE(e3 == e1);
}
