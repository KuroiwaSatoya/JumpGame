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

	// ��̐F
	int unitColor, unitLineColor;

	// ��̍��W
	Vector2 position;

	// ��̏c���Ɖ���
	Vector2 size;

	// �o�����Ă��邩�ǂ���
	bool isAppearing;

	// ��ԍŏ���Unit�͓������Ȃ�����
	bool isFirstUnit;
};
