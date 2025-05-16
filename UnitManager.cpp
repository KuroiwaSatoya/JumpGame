#include "UnitManager.h"
#include "Screen.h"
#include <cstdlib>

UnitManager::UnitManager() : spawnTimer(0.0f) {
    for (int i = 0; i < MAX_UNITS; ++i) {
        units[i] = nullptr;
    }

    // �ŏ���Unit����������
    units[0] = new Unit(true); // ������bool�^���ƍŏ���Unit�ɂȂ�
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

            // ��ʊO�ɏo����폜
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
