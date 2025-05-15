#pragma once
#include "GameManagerMain.h"
#include "PlayerMove.h"

class Camera : public GameManagerMain {
public:

	Camera(PlayerMove& _playerMove);

	void Update() override;

	float GetCameraY() const { return cameraY; };

private:
	int cameraY;

	// playerMove‚Ì•Û
	PlayerMove& playerMove;
};
