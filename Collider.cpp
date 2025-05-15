#include "Collider.h"
#include <cmath>
#include <algorithm>

using namespace std;

Collider::Collider(PlayerMove& _playerMove, PlayerJump& _playerJump, Unit* _units) : playerMove(_playerMove), playerJump(_playerJump){

	units = _units;

	unitCount = 10;

    playerPosition = _playerMove.GetPosition();

    lastPlayerPosition = playerPosition; // PlayerMove�Ɏ�������̂�����

    unitPosition = _units->GetPosition();

    playerSize = _playerMove.GetImageSize();
}

    //// �e���j�b�g�ƃv���C���[�̓����蔻����`�F�b�N
    //for (int i = 0; i < unitCount; i++) {
    //    unitPosition = units[i].GetPosition();
    //    unitSize = units[i].GetSize();

    //    // �����蔻��
    //    if (playerPosition.x < unitPosition.x + unitSize.x &&
    //        playerPosition.x + playerSize.x > unitPosition.x &&
    //        playerPosition.y < unitPosition.y + unitSize.y &&
    //        playerPosition.y + playerSize.y > unitPosition.y) {
    //        
    //        HandleCollisions(&units[i]);
    //    }
    //    else {
    //        HandleNoCollisions();
    //    }
    //}

void Collider::Update() {

    // �O��̈ʒu��ۑ�
    lastPlayerPosition = playerPosition;

    // ���݈ʒu���X�V
    playerPosition = playerMove.GetPosition();
    unitPosition = units->GetPosition();
    unitSize = units->GetSize();
    playerSize = playerMove.GetImageSize(); // �v��Ȃ����O�̂���

    // ��`�̓����蔻��
    if (playerPosition.x < unitPosition.x + unitSize.x &&
        playerPosition.x + playerSize.x > unitPosition.x &&
        playerPosition.y < unitPosition.y + unitSize.y &&
        playerPosition.y + playerSize.y > unitPosition.y) {

        // Unit��Player���ǂꂾ���߂荞��ł��邩���Z�o
        float overlapX = min(playerPosition.x + playerSize.x, unitPosition.x + unitSize.x) - max(playerPosition.x, unitPosition.x);
        float overlapY = min(playerPosition.y + playerSize.y, unitPosition.y + unitSize.y) - max(playerPosition.y, unitPosition.y);

        // �㉺�ł߂荞��ł�����
        if (overlapY < overlapX) {
            // ���S��Y���W���r���APlayer��Unit�̏�ɂ���̂����ɂ���̂�����
            if (playerPosition.y + playerSize.y / 2 < unitPosition.y + unitSize.y / 2) {
                HitFeet(units);
            }
            else {
                HitHead(units);
            }
        }
        else {
            // �����悤�ɍ��ɂ��邩�E�ɂ��邩����
            if (playerPosition.x + playerSize.x / 2 < unitPosition.x + unitSize.x / 2) {
                HitRight(units);
            }
            else {
                HitLeft(units);
            }
        }
    }
    // �����ŏ���
    else if (playerPosition.y > 718 - playerSize.y) {

        // Player��isGround��true�ɂ���
        playerMove.SetIsGround(true);

    }
    else {
        HandleNoCollisions();
    }
}



// ���������ꍇ�̏��� ������Ԃ���
void Collider::HitFeet(Unit* _unit) {
    
    // Player��isGround��true�ɂ���
    playerMove.SetIsGround(true);

    // Player��Unit�ɂ߂荞�܂Ȃ��悤��Y���W�𒲐�
    playerMove.SetPositionY(unitPosition.y - playerSize.y);

}

// �����Ԃ����ꍇ
void Collider::HitHead(Unit* _unit) {

    // Player��Unit����ɍs���Ȃ��悤��Y���W�𒲐�
    playerMove.SetPositionY(unitPosition.y + unitSize.y);

    playerJump.StopJump();

    playerMove.SetIsGround(false);

}

// �̂̉E�����Ԃ������ꍇ
void Collider::HitRight(Unit* _unit) {

    playerMove.SetPositionX(unitPosition.x - playerSize.x);

}

// �������Ԃ������ꍇ
void Collider::HitLeft(Unit* _unit) {

    playerMove.SetPositionX(unitPosition.x + unitSize.x);

}

// �������ĂȂ��ꍇ�̏���
void Collider::HandleNoCollisions() {

    playerMove.SetIsGround(false);

}