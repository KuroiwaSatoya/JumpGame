#pragma once

#include "Unit.h"

class UnitManager : public StageMain{
public:

    UnitManager();
    ~UnitManager();

    void Update() override;

private:

    // Unitの最大の数
    static const int MAX_UNITS = 10;

    float spawnTimer;

    const float SPAWN_INTERVAL = 5.0f;

    // 出現させるUnitのPosition
    Vector2 position;

    // インスタンスの宣言
    Unit* units[MAX_UNITS];

    void SpawnUnit();

    void DestroyUnit(int index);
};
