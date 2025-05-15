#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerRun : public PlayerMain {
public:
	PlayerRun(PlayerMove& _playerMove);

	void Update() override;

private:

	// X•ûŒü‚Ö‚ÌˆÚ“®
	float directionX;

	// ‘–‚é‘¬“x
	float speed;

	// ’n–Ê‚É‚Â‚¢‚Ä‚¢‚é‚©
	bool isGround;

	//PlayerMove‚Ì•Û
	PlayerMove& playerMove;
};
