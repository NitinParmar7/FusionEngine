#include "SystemManager.h"

void SystemManager::updateAll(float dt)
{
	for (auto& system : systems)
	{
		system->update(dt);
	}
}
