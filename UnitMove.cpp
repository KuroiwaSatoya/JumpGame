#include <cstdlib>
#include "UnitMove.h"
#include "DxLib.h"

UnitMove::UnitMove(Unit& _unit) : unit(_unit) {

    x = _unit.GetX();

    isFirstUnit = _unit.GetIsFirstUnit();

    // speed��1.0f�`2.5f�̊Ԃɐݒ�
    speed = 1.0f + static_cast<float>(rand()) / RAND_MAX * 1.5f;

    // �E���痈�邩�����痈�邩�������_���ɐݒ�
    isComingFromLeft = rand() % 2 == 0;
}

void UnitMove::Update() {

    if (!isFirstUnit) {

        x = unit.GetX();

        if (isComingFromLeft) {

            x += speed * deltaTime;

        }
        else {

            x -= speed * deltaTime;

        }

        unit.SetX(x);
    }
}

void UnitMove::Display() {
    
}