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

	// プレイヤーの画像
	int playerImage;

	// プレイヤーの画像の縦横のサイズ
	Vector2 imageSize;

	// プレイヤーの画像の拡大率
	float scale;

	// プレイヤーの座標
	Vector2 position;

	//PlayerMoveの保持
	PlayerMove& playerMove;
};
