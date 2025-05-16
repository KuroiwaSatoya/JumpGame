#include "UnitManager.h"
#include <cstdlib>

UnitManager::UnitManager() : spawnTimer(0.0f) {
    for (int i = 0; i < MAX_UNITS; ++i) {
        units[i] = nullptr;
    }

    // 最初のUnitだけ初期化
    units[0] = new Unit(true); // 引数がbool型だと最初のUnitになる
}

UnitManager::~UnitManager() {
    for (int i = 0; i < MAX_UNITS; ++i) {
        delete units[i];
        units[i] = nullptr;
    }
}

void UnitManager::Update() {
    spawnTimer += deltaTime;

    if (spawnTimer >= SPAWN_INTERVAL) {
        SpawnUnit();
        spawnTimer = 0.0f;
    }

    for (int i = 0; i < MAX_UNITS; ++i) {
        if (units[i]) {
            units[i]->Update();

            // 画面外に出たら削除（右方向に進むと仮定）
            if (units[i]->GetPosition().x > 1280 || units[i]->GetPosition().x < -100) {
                DestroyUnit(i);
            }
        }
    }
}

void UnitManager::SpawnUnit() {
    for (int i = 1; i < MAX_UNITS; ++i) { 
        if (!units[i]) {
            units[i] = new Unit({ 0, 600 });
            break;
        }
    }
}

void UnitManager::DestroyUnit(int index) {
    if (units[index]) {
        delete units[index];
        units[index] = nullptr;
    }
}
