#include "Unit.h"
#include "DxLib.h"

// 1つ目のUnitの初期化
Unit::Unit(bool _isFirstUnit) {
	// GetColor(255, 255, 255)と同じ(16進数の色表記でOK)
	unitColor = 0xFFFFFF;

	unitLineColor = 0x000000;

	position = Vector2(550, 500);

	size = Vector2(200, 30);

	isAppearing = true;

	isFirstUnit = _isFirstUnit;
}

// 2つ目以降
Unit::Unit(){
	// GetColor(255, 255, 255)と同じ(16進数の色表記でOK)
	unitColor = 0xFFFFFF;

	unitLineColor = 0x000000;

	position = Vector2(550, 500);

	size = Vector2(200, 30);

	isAppearing = true;

	isFirstUnit = false;
}

void Unit::Update() {
	
}

void Unit::Display() {
	DrawBox(
		// 描画する四角形の左上頂点
		position.x, position.y,
		// 右下頂点
		position.x + size.x, position.y + size.y,
		//塗りつぶすか
		unitColor, TRUE);

	// 縁取り
	DrawBox(
		// 描画する四角形の左上頂点
		position.x, position.y,
		// 右下頂点
		position.x + size.x, position.y + size.y,
		//塗りつぶすか
		unitLineColor, FALSE);
}