#include <cstdlib>
#include "UnitMove.h"
#include "DxLib.h"

UnitMove::UnitMove(Unit& _unit) : unit(_unit) {

    x = _unit.GetPosition().x;

    isFirstUnit = _unit.GetIsFirstUnit();

    // speedを1.0f〜2.5fの間に設定
    speed = 1.0f + static_cast<float>(rand()) / RAND_MAX * 1.5f;

    // 右から来るか左から来るかをランダムに設定
    isComingFromLeft = rand() % 2 == 0;
}

void UnitMove::Update() {

    if (!isFirstUnit) {

        x = unit.GetPosition().x;

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