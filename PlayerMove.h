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

	void SetImageSize(const Vector2& _imageSize) { imageSize = _imageSize; } // �\���̂Ȃ̂�const��t���ĎQ�Ɠn��

	void SetIsGround(bool _isGround) { isGround = _isGround; }

private:

	// Player��x,y���W
	Vector2 position;

	// Player�̈ړ�����
	Vector2 direction, lastDirection;

	// �f���^�^�C��
	float deltaTime;

	// �v���C���[�̉摜�̏c���̃T�C�Y
	Vector2 imageSize;

	// Player���n�ʂɒ����Ă��邩
	bool isGround;
};
