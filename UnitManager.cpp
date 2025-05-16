#include "UnitManager.h"
#include "Screen.h"
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
    
    // 本当は移動距離に応じてスポーンさせたい
    spawnTimer += deltaTime;

    if (spawnTimer >= SPAWN_INTERVAL) {
        SpawnUnit();
        spawnTimer = 0.0f;
    }

    for (int i = 0; i < MAX_UNITS; ++i) {
        if (units[i]) {
            units[i]->Update();

            // 画面外に出たら削除
            if (units[i]->GetPosition().x > SCREEN_WIDTH || units[i]->GetPosition().x < SCREEN_ORIGIN
                && units[i]->GetPosition().y > SCREEN_HEIGHT || units[i]->GetPosition().y < SCREEN_ORIGIN)
            {
                DestroyUnit(i);
            }
        }
    }
}

void UnitManager::SpawnUnit() {
    for (int i = 1; i < MAX_UNITS; ++i) { 
        if (!units[i]) {
            units[i] = new Unit(position);
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
