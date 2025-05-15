#include "Background.h"
#include "DxLib.h"

Background::Background(LoadImages& _loadImages) {
	backgroundImage = _loadImages.backgroundImage;

	GetGraphSize(backgroundImage, &backgroundImageWidth, &backgroundImageHeight);

	x = 0, y = 0;
}

void Background::Update() {
	
}

void Background::Display() {

	y = 0;
	while (y < SCREEN_HEIGHT) {
		x = 0;
		while (x < SCREEN_WIDTH) {
			DrawGraph(x, y,			// •`‰æ‚·‚éÀ•W 
				backgroundImage,	// •`‰æ‚·‚é‰æ‘œ‚Ìƒnƒ“ƒhƒ‹
				FALSE);				// ”wŒi‚ð“§‰ß‚·‚é‚©‚Ç‚¤‚©
			x += backgroundImageWidth;
		}
		y += backgroundImageHeight;
	}

}