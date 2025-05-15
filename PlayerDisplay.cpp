#include "PlayerDisplay.h"
#include "DxLib.h"

PlayerDisplay::PlayerDisplay(LoadImages& _loadImages, PlayerMove& _playerMove) : playerMove(_playerMove) {

	playerImage = _loadImages.playerImage;

	// Vector2はfloat型なので、一時的に変数を作成
	int width, height;
	GetGraphSize(playerImage, &width, &height);

	scale = 0.15f;

	// floatに変換してVector2に代入
	imageSize = Vector2(width * scale, height * scale);

	_playerMove.SetImageSize(imageSize);
}

void PlayerDisplay::Update() {

	position.x = playerMove.GetX();

	position.y = playerMove.GetY();

}

void PlayerDisplay::Display() {

	// 拡大して描画できる
	DrawExtendGraphF(
		position.x, position.y, // 左上座標
		position.x + imageSize.x, position.y + imageSize.y, // 右下座標
		playerImage, TRUE);
}