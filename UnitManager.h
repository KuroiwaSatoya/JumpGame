#pragma once

#include "Unit.h"

class UnitManager : public StageMain{
public:

    UnitManager();
    ~UnitManager();

    void Update() override;

private:

    // Unit�̍ő�̐�
    static const int MAX_UNITS = 10;

    float spawnTimer;

    const float SPAWN_INTERVAL = 5.0f;

    // �o��������Unit��Position
    Vector2 position;

    // �C���X�^���X�̐錾
    Unit* units[MAX_UNITS];

    void SpawnUnit();

    void DestroyUnit(int index);
};
