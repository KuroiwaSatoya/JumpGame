#include "PlayerDisplay.h"
#include "DxLib.h"

PlayerDisplay::PlayerDisplay(LoadImages& _loadImages, PlayerMove& _playerMove) : playerMove(_playerMove) {

	playerImage = _loadImages.playerImage;

	// Vector2��float�^�Ȃ̂ŁA�ꎞ�I�ɕϐ����쐬
	int width, height;
	GetGraphSize(playerImage, &width, &height);

	scale = 0.15f;

	// float�ɕϊ�����Vector2�ɑ��
	imageSize = Vector2(width * scale, height * scale);

	_playerMove.SetImageSize(imageSize);
}

void PlayerDisplay::Update() {

	position.x = playerMove.GetX();

	position.y = playerMove.GetY();

}

void PlayerDisplay::Display() {

	// �g�債�ĕ`��ł���
	DrawExtendGraphF(
		position.x, position.y, // ������W
		position.x + imageSize.x, position.y + imageSize.y, // �E�����W
		playerImage, TRUE);
}