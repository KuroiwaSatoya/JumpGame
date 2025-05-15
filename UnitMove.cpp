#include <cstdlib>
#include "UnitMove.h"
#include "DxLib.h"

UnitMove::UnitMove(Unit& _unit) : unit(_unit) {

    x = _unit.GetX();

    isFirstUnit = _unit.GetIsFirstUnit();

    // speed‚ğ1.0f`2.5f‚ÌŠÔ‚Éİ’è
    speed = 1.0f + static_cast<float>(rand()) / RAND_MAX * 1.5f;

    // ‰E‚©‚ç—ˆ‚é‚©¶‚©‚ç—ˆ‚é‚©‚ğƒ‰ƒ“ƒ_ƒ€‚Éİ’è
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