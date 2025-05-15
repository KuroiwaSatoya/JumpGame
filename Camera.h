#pragma once
#include "GameManagerMain.h"
#include "PlayerMove.h"

class Camera : public GameManagerMain {
public:

	Camera(PlayerMove& _playerMove);

	void Update() override;

	float GetCameraY() const { return cameraY; };

private:

	// ƒJƒƒ‰‚ÌÀ•W
	int cameraY;

	// playerMove‚Ì•Û
	PlayerMove& playerMove;
};
