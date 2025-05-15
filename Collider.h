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

    // Player, Unit�̍��W
    Vector2 playerPosition, lastPlayerPosition, unitPosition;

    // Player, Unit�̉摜�T�C�Y
    Vector2 playerSize, unitSize;

    // �e�N���X�̃C���X�^���X�̕ێ�
    PlayerMove& playerMove;
    PlayerJump& playerJump;
    Unit* units;
};