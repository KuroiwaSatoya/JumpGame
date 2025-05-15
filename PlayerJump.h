#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerJump : public PlayerMain {
public:
	PlayerJump(PlayerMove& _playerMove);

	void Update() override;

	void StopJump();

private:

	// ����(�}�C�i�X�̏�����ƂȂ�)
	float directionY;

	// ��
	float jumpForce;

	// �n�ʂɂ��Ă��邩
	bool isGround;

	//PlayerMove�̕ێ�
	PlayerMove& playerMove;
};
