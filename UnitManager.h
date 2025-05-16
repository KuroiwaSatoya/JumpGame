#pragma once

#include "Unit.h"

class UnitManager : public StageMain{
public:

    UnitManager();
    ~UnitManager();

    void Update() override;

private:
    static const int MAX_UNITS = 10;
    Unit* units[MAX_UNITS];
    float spawnTimer;
    const float SPAWN_INTERVAL = 5.0f;

    void SpawnUnit();
    void DestroyUnit(int index);
};
