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

	float GetX() const { return position.x; }

	bool GetIsFirstUnit() const { return isFirstUnit; }

	Vector2 GetPosition() const { return position; }

	Vector2 GetSize() const { return size; }

	void SetX(float _x) { position.x = _x; }

private:

	// ‘ä‚ÌF
	int unitColor, unitLineColor;

	// ‘ä‚ÌÀ•W
	Vector2 position;

	// ‘ä‚Ìc•‚Æ‰¡•
	Vector2 size;

	// oŒ»‚µ‚Ä‚¢‚é‚©‚Ç‚¤‚©
	bool isAppearing;

	// ˆê”ÔÅ‰‚ÌUnit‚Í“®‚©‚³‚È‚¢‚½‚ß
	bool isFirstUnit;
};
