#include "Camera.h"

Camera::Camera(PlayerMove& _playerMove) : playerMove(_playerMove) {

	cameraY = 0;
}

void Camera::Update() {

	// 常に一定の速度上がれば良い。
	// Displayが含まれるスクリプトに委譲させ
	// cameraY分y座標のDisplayを下げる

}