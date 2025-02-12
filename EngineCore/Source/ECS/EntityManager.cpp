#include "EntityManager.h"

Entity EntityManager::createEntity()
{
    if (!freeEntities.empty())
    {
        Entity id = freeEntities.front();
        freeEntities.pop();
        return id;
    }
    return nextEntity++;
}

void EntityManager::destroyEntity(Entity entity)
{
    //TODO: In a complete ECS, you would also remove associated components.
    freeEntities.push(entity);
}


