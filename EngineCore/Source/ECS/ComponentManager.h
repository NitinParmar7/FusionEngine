#include <optional>
#include <functional>
#include "Entity.h"

template<typename Component>
class ComponentManager {
public:
    void addComponent(Entity entity, const Component& component) {
        components[entity] = component;
    }

    // Returns an optional reference to the component.
    std::optional<std::reference_wrapper<Component>> getComponent(Entity entity) {
        auto it = components.find(entity);
        if (it != components.end()) {
            return it->second;
        }
        return std::nullopt;
    }

    void removeComponent(Entity entity) {
        components.erase(entity);
    }

    const std::unordered_map<Entity, Component>& getAllComponents() const {
        return components;
    }

private:
    std::unordered_map<Entity, Component> components;
};
