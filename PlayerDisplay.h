#pragma once
#include "LoadImages.h"
#include "Vector2.h"
#include "PlayerMain.h"
#include "PlayerMove.h"

class PlayerDisplay : public PlayerMain {
public:

	PlayerDisplay(LoadImages& _loadImages, PlayerMove& _playerMove);

	void Update() override;

	void Display() override;

private:

	// �v���C���[�̉摜
	int playerImage;

	// �v���C���[�̉摜�̏c���̃T�C�Y
	Vector2 imageSize;

	// �v���C���[�̉摜�̊g�嗦
	float scale;

	// �v���C���[�̍��W
	Vector2 position;

	//PlayerMove�̕ێ�
	PlayerMove& playerMove;
};
