#include "PlayerJump.h"
#include "DxLib.h"

PlayerJump::PlayerJump(PlayerMove& _playerMove) : playerMove(_playerMove) {

	directionY = 0;

	jumpForce = 800;

    isGround = false;
}

void PlayerJump::Update() {

    // playerMove����isGround�������Ă���
    isGround = playerMove.GetIsGround();

    // �X�y�[�X�L�[������������Ă�����
    if (CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP)) {

        if (isGround) {

            directionY = -jumpForce;

        }
    }
    // ������Ă��Ȃ��Ȃ�directionY��0��
    else if (isGround) {
        StopJump();
    }

    playerMove.AddDirectionY(directionY);
}

void PlayerJump::StopJump() {

    directionY = 0;

}