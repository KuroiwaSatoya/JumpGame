#include "PlayerJump.h"
#include "DxLib.h"

PlayerJump::PlayerJump(PlayerMove& _playerMove) : playerMove(_playerMove) {

	directionY = 0;

	jumpForce = 800;

    isGround = false;
}

void PlayerJump::Update() {

    // playerMoveからisGroundを持ってくる
    isGround = playerMove.GetIsGround();

    // スペースキーか↑が押されていたら
    if (CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP)) {

        if (isGround) {

            directionY = -jumpForce;

        }
    }
    // 押されていないならdirectionYを0に
    else if (isGround) {
        StopJump();
    }

    playerMove.AddDirectionY(directionY);
}

void PlayerJump::StopJump() {

    directionY = 0;

}