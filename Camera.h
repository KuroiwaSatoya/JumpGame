#pragma once
#include "GameManagerMain.h"
#include "PlayerMove.h"

class Camera : public GameManagerMain {
public:

	Camera(PlayerMove& _playerMove);

	void Update() override;

	float GetCameraY() const { return cameraY; };

private:

	// �J�����̍��W
	int cameraY;

	// playerMove�̕ێ�
	PlayerMove& playerMove;
};
