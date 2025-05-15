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

    // Player, Unit�̍��W
    Vector2 playerPosition, unitPosition;

    // Player, Unit�̉摜�T�C�Y
    Vector2 playerSize, unitSize;

    // �e�N���X�̃C���X�^���X�̕ێ�
    PlayerMove& playerMove;
    Unit* units;
};