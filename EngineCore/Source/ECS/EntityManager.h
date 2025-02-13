#pragma once
#include "Entity.h"
#include <queue>
#include "EngineAPI.h"


// EntityManager is responsible for creating and recycling entities.
// We use a simple queue to store recycled IDs.
class EntityManager
{
public:

	// [[nodiscard]] is a C++17 attribute that warns if the return value is ignored.
	// This is useful here to ensure that when an entity is created, the caller doesn't discard its ID.
    [[nodiscard]] inline Entity createEntity() {
        if (!freeEntities.empty()) {
            Entity id = freeEntities.front();
            freeEntities.pop();
            return id;
        }
        return nextEntity++;
    }

    // Marked inline to ensure definition is available.
    inline void destroyEntity(Entity entity) {
        freeEntities.push(entity);
    }

private:

	// It initializes nextEntity to 0 when an instance is created.
	Entity nextEntity{ 0 };

	// std::queue used to store recycled entity IDs.
	std::queue<Entity> freeEntities;
};
