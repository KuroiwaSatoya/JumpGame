#pragma once
#include "Vector2.h"
#include "StageMain.h"

class Unit : public StageMain {
public:

	Unit(bool _isFirstUnit);

	Unit();

	~Unit() = default;

	void Update() override;

	void Display() override;

	bool GetIsFirstUnit() const { return isFirstUnit; }

	Vector2 GetPosition() const { return position; }

	Vector2 GetSize() const { return size; }

	void SetX(float _x) { position.x = _x; }

private:

	// 台の色
	int unitColor, unitLineColor;

	// 台の座標
	Vector2 position;

	// 台の縦幅と横幅
	Vector2 size;

	// 出現しているかどうか
	bool isAppearing;

	// 一番最初のUnitは動かさないため
	bool isFirstUnit;
};
