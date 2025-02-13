#pragma once
#include "System.h"
#include <PositionData.h>
#include <ComponentManager.h>

class DummyMovementSystem : public System {
public:
    // The system operates on a ComponentManager for Position.
    DummyMovementSystem(ComponentManager<Position>& posManager);

    void update(float dt) override;
private:
    ComponentManager<Position>& positionManager;
};
