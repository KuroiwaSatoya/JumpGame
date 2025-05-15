#include "LoadImages.h"
#include "DxLib.h"

LoadImages::LoadImages() {

	playerImage = LoadGraph("Images/Player.png");

	backgroundImage = LoadGraph("Images/Background.png");
}