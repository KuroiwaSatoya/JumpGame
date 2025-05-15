#pragma once
#include "GameManagerMain.h"
#include "Screen.h"
#include "LoadImages.h"

class Background : public GameManagerMain {
public:

	Background(LoadImages& _loadImages);

	void Update() override;

	void Display() override;

private:
	// �w�i�̉摜
	int backgroundImage;

	// �w�i�摜�̏c���̑傫��
	int backgroundImageWidth, backgroundImageHeight;

	// �w�i��`�悷����W
	int x, y;
};
