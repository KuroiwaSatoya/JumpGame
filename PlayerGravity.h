#pragma once
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerGravity : public PlayerMain {
public:
	PlayerGravity(PlayerMove& _playerMove);

	void Update() override;

private:

	// �d�͉����x
	float playerGravity;

	// Y���̕���
	float directionY;

	// �n�ʔ���
	bool isGround;

	//PlayerMove�̕ێ�
	PlayerMove& playerMove;
};
