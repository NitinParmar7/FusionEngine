#pragma once
#include <memory>
#include "System.h"
#include <vector>

class SystemManager {
public:

	template<typename T, typename... Args>
	T* registerSystem(Args&&... args)
	{
		static_assert(std::is_base_of_v<System, T>, "T must derive from System");
		auto system = std::make_unique<T>(std::forward<Args>(args)...);
		T* systemPtr = system.get();
		systems.push_back(std::move(system));
		return systemPtr;
	}


	void updateAll(float dt);

private:

	// A container for all systems.
	std::vector<std::unique_ptr<System>> systems;
};
