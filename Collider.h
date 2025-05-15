#pragma once
#include "Vector2.h"
#include "GameManagerMain.h"
#include "PlayerMove.h"
#include "PlayerJump.h"
#include "Unit.h"

class Collider : public GameManagerMain{
public:

    Collider(PlayerMove& _playerMove, PlayerJump& _playerJump, Unit* _units);

    void Update() override;

    void HitFeet(Unit* _unit);

    void HitHead(Unit* _unit);

    void HitRight(Unit* _unit);

    void HitLeft(Unit* _unit);

    void HandleNoCollisions();

private:

    int unitCount;

    // Player, Unitの座標
    Vector2 playerPosition, lastPlayerPosition, unitPosition;

    // Player, Unitの画像サイズ
    Vector2 playerSize, unitSize;

    // 各クラスのインスタンスの保持
    PlayerMove& playerMove;
    PlayerJump& playerJump;
    Unit* units;
};