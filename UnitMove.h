#pragma once
#include "Unit.h"
#include "StageMain.h"

class UnitMove : public StageMain {
public:

	UnitMove(Unit& _unit);

	void Update() override;

	void Display() override;

private:
	// ˆÚ“®‘¬“x
	float speed;

	// Unit‚É‘ã“ü‚·‚é‚½‚ß‚Ìx
	float x;

	// ‰E‚©‚ç—ˆ‚é‚©¶‚©‚ç—ˆ‚é‚©
	bool isComingFromLeft;

	// Å‰‚ÌUnit‚©‚Ç‚¤‚©
	bool isFirstUnit;

	// Unit‚ğ•Û
	Unit& unit;
};