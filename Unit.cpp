#include "Unit.h"
#include "DxLib.h"

// 1�ڂ�Unit�̏�����
Unit::Unit(bool _isFirstUnit) {
	// GetColor(255, 255, 255)�Ɠ���(16�i���̐F�\�L��OK)
	unitColor = 0xFFFFFF;

	unitLineColor = 0x000000;

	position = Vector2(550, 500);

	size = Vector2(200, 30);

	isAppearing = true;

	isFirstUnit = _isFirstUnit;
}

// 2�ڈȍ~
Unit::Unit(){
	// GetColor(255, 255, 255)�Ɠ���(16�i���̐F�\�L��OK)
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
		// �`�悷��l�p�`�̍��㒸�_
		position.x, position.y,
		// �E�����_
		position.x + size.x, position.y + size.y,
		//�h��Ԃ���
		unitColor, TRUE);

	// �����
	DrawBox(
		// �`�悷��l�p�`�̍��㒸�_
		position.x, position.y,
		// �E�����_
		position.x + size.x, position.y + size.y,
		//�h��Ԃ���
		unitLineColor, FALSE);
}