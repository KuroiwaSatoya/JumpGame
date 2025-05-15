#include "Collider.h"

Collider::Collider(PlayerMove& _playerMove, Unit* _units) : playerMove(_playerMove){

	units = _units;

	unitCount = 10;

    playerPosition = _playerMove.GetPosition();

    unitPosition = _units->GetPosition();

    playerSize = _playerMove.GetImageSize();
}

void Collider::Update() {
    // �v���C���[�̈ʒu���X�V
    playerPosition = playerMove.GetPosition();

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

    unitPosition = units->GetPosition();
    unitSize = units->GetSize();

    // unit��player�̓����蔻��
    if (playerPosition.x < unitPosition.x + unitSize.x &&
        playerPosition.x + playerSize.x > unitPosition.x &&
        playerPosition.y < unitPosition.y + unitSize.y &&
        playerPosition.y + playerSize.y > unitPosition.y) {

        // player���㏸���Ȃ瓖���蔻���ύX
        if (playerMove.GetLastDirectionY() < 0) {

            HitHead(units);

        }
        else {
            HitFeet(units);
        }
    }
    else {
        HandleNoCollisions();
    }

    if (playerPosition.y > 1279) {

        // Player��isGround��true�ɂ���
        playerMove.SetIsGround(true);

    }
}



// ���������ꍇ�̏���
void Collider::HitFeet(Unit* unit) {
    
    // Player��isGround��true�ɂ���
    playerMove.SetIsGround(true);

    // Player��Unit�ɂ߂荞�܂Ȃ��悤��Y���W�𒲐�
    playerMove.SetPositionY(unitPosition.y - playerSize.y);

}

void Collider::HitHead(Unit* unit) {

    // Player��isGround��false�ɂ���
    playerMove.SetIsGround(false);

    // Player��Unit����ɍs���Ȃ��悤��Y���W�𒲐�
    playerMove.SetPositionY(unitPosition.y + unitSize.y);

}

// �������ĂȂ��ꍇ�̏���
void Collider::HandleNoCollisions() {

    playerMove.SetIsGround(false);

}