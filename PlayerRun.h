#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerRun : public PlayerMain {
public:
	PlayerRun(PlayerMove& _playerMove);

	void Update() override;

private:

	// X方向への移動
	float directionX;

	// 走る速度
	float speed;

	// 地面についているか
	bool isGround;

	//PlayerMoveの保持
	PlayerMove& playerMove;
};
