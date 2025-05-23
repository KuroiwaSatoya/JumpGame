#pragma once
#include "Unit.h"
#include "StageMain.h"

class UnitMove : public StageMain {
public:

	UnitMove(Unit& _unit);

	void Update() override;

	void Display() override;

private:
	// 移動速度
	float speed;

	// Unitに代入するためのx
	float x;

	// 右から来るか左から来るか
	bool isComingFromLeft;

	// 最初のUnitかどうか
	bool isFirstUnit;

	// Unitを保持
	Unit& unit;
};