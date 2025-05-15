#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerGravity : public PlayerMain {
public:
	PlayerGravity(PlayerMove& _playerMove);

	void Update() override;

private:

	// d—Í‰Á‘¬“x
	float playerGravity;

	// Y²‚Ì•ûŒü
	float directionY;

	// ’n–Ê”»’è
	bool isGround;

	//PlayerMove‚Ì•Û
	PlayerMove& playerMove;
};
