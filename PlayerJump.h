#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerJump : public PlayerMain {
public:
	PlayerJump(PlayerMove& _playerMove);

	void Update() override;

	void StopJump();

private:

	// 方向(マイナスの上方向となる)
	float directionY;

	// 力
	float jumpForce;

	// 地面についているか
	bool isGround;

	//PlayerMoveの保持
	PlayerMove& playerMove;
};
