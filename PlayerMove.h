#pragma once
#include "Screen.h"
#include "Vector2.h"
#include "PlayerMain.h"

class PlayerMove : public PlayerMain{
public:

	PlayerMove();

	void Update() override;

	float GetX() const { return position.x; }

	float GetY() const { return position.y; }

	float GetLastDirectionY() const { return lastDirection.y; }

	Vector2 GetPosition() const { return position; }

	Vector2 GetImageSize() const { return imageSize; }

	bool GetIsGround() const { return isGround; }

	void SetPositionY(float _positionY) { position.y = _positionY; }

	void AddDirectionX(float _directionX) { direction.x += _directionX; }

	void AddDirectionY(float _directionY) { direction.y += _directionY; }

	void SetDeltaTime(float _deltaTime) { deltaTime = _deltaTime; }

	void SetImageSize(const Vector2& _imageSize) { imageSize = _imageSize; } // 構造体なのでconstを付けて参照渡し

	void SetIsGround(bool _isGround) { isGround = _isGround; }

private:

	// Playerのx,y座標
	Vector2 position;

	// Playerの移動方向
	Vector2 direction, lastDirection;

	// デルタタイム
	float deltaTime;

	// プレイヤーの画像の縦横のサイズ
	Vector2 imageSize;

	// Playerが地面に着いているか
	bool isGround;
};
