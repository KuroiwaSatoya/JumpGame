#pragma once
#include "GameManagerMain.h"
#include "PlayerMove.h"

class Camera : public GameManagerMain {
public:

	Camera(PlayerMove& _playerMove);

	void Update() override;

	float GetCameraY() const { return cameraY; };

private:

	// カメラの座標
	int cameraY;

	// playerMoveの保持
	PlayerMove& playerMove;
};
