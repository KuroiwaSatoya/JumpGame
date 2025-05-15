#include "PlayerGravity.h"

PlayerGravity::PlayerGravity(PlayerMove& _playerMove) : playerMove(_playerMove) {

	playerGravity = 10.0f;
	directionY = 0;
	isGround = false;
}

void PlayerGravity::Update() {

	isGround = playerMove.GetIsGround();

	if (!isGround) {

		directionY += playerGravity;
	}
	else {

		directionY = 0;
	}

	playerMove.AddDirectionY(directionY);
}

