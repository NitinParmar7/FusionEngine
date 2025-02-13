#pragma once

#include "System.h"
#include "EngineAPI.h"  // Defines ENGINE_API
#include <memory>
#include <vector>
#include <type_traits>
#include <utility>

class ENGINE_API SystemManager {
public:
    SystemManager();
    ~SystemManager();

    // Delete copy operations.
    SystemManager(const SystemManager&) = delete;
    SystemManager& operator=(const SystemManager&) = delete;

    template<typename T, typename... Args>
    T* registerSystem(Args&&... args) {
        static_assert(std::is_base_of_v<System, T>, "T must derive from System");
        auto system = std::make_unique<T>(std::forward<Args>(args)...);
        T* systemPtr = system.get();
        pImpl.systems.push_back(std::move(system));
        return systemPtr;
    }

    void updateAll(float dt) {
        for (auto& system : pImpl.systems) {
            system->update(dt);
        }
    }

private:
    // Now we define the Impl type fully in the header.
    struct Impl {
        std::vector<std::unique_ptr<System>> systems;
    };

    // Instead of a pointer, we store Impl by value.
    Impl pImpl;
};

inline SystemManager::SystemManager() : pImpl{} {}
inline SystemManager::~SystemManager() = default;
