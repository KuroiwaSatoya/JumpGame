#pragma once
#include "Vector2.h"
#include "GameManagerMain.h"
#include "PlayerMove.h"
#include "Unit.h"

class Collider : public GameManagerMain{
public:

    Collider(PlayerMove& _playerMove, Unit* _units);

    void Update() override;

    void HitFeet(Unit* unit);

    void HitHead(Unit* unit);

    void HandleNoCollisions();

private:

    int unitCount;

    // Player, Unitの座標
    Vector2 playerPosition, unitPosition;

    // Player, Unitの画像サイズ
    Vector2 playerSize, unitSize;

    // 各クラスのインスタンスの保持
    PlayerMove& playerMove;
    Unit* units;
};