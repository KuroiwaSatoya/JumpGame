#include "PlayerJump.h"
#include "DxLib.h"

PlayerJump::PlayerJump(PlayerMove& _playerMove) : playerMove(_playerMove) {

	directionY = 0;

	jumpForce = 600;

    isGround = false;
}

void PlayerJump::Update() {

    isGround = playerMove.GetIsGround();

    if (CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP)) {

        if (isGround) {

            directionY = -jumpForce;

        }
    }
    else if (isGround) {
        directionY = 0;
    }

    playerMove.AddDirectionY(directionY);
}