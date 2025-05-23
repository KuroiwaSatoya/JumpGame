#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerGravity : public PlayerMain {
public:
	PlayerGravity(PlayerMove& _playerMove);

	void Update() override;

private:

	// 重力加速度
	float playerGravity;

	// Y軸の方向
	float directionY;

	// 地面判定
	bool isGround;

	//PlayerMoveの保持
	PlayerMove& playerMove;
};
