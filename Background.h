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
	// ”wŒi‚Ì‰æ‘œ
	int backgroundImage;

	// ”wŒi‰æ‘œ‚Ìc‰¡‚Ì‘å‚«‚³
	int backgroundImageWidth, backgroundImageHeight;

	// ”wŒi‚ğ•`‰æ‚·‚éÀ•W
	int x, y;
};
