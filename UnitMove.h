#pragma once
#include "Unit.h"
#include "StageMain.h"

class UnitMove : public StageMain {
public:

	UnitMove(Unit& _unit);

	void Update() override;

	void Display() override;

private:
	// �ړ����x
	float speed;

	// Unit�ɑ�����邽�߂�x
	float x;

	// �E���痈�邩�����痈�邩
	bool isComingFromLeft;

	// �ŏ���Unit���ǂ���
	bool isFirstUnit;

	// Unit��ێ�
	Unit& unit;
};