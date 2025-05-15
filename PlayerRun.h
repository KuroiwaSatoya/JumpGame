#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerRun : public PlayerMain {
public:
	PlayerRun(PlayerMove& _playerMove);

	void Update() override;

private:

	// X�����ւ̈ړ�
	float directionX;

	// ���鑬�x
	float speed;

	// �n�ʂɂ��Ă��邩
	bool isGround;

	//PlayerMove�̕ێ�
	PlayerMove& playerMove;
};
